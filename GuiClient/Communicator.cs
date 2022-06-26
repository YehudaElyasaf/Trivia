﻿using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;

static class Const
{
    public const int SERVER_PORT = 4242;
    public const string SERVER_IP = "127.0.0.1";
    public const int MAX_BUFFER_SIZE = 4096;
    public const string OPENING_MESSAGE = "Hello";
    public const char LIST_SEPERATOR = ',';

    //message codes
    public const int TIMEOUT_CODE = 0;
    public const int ERROR_CODE = 1;
    public const int LOGIN_CODE = 2;
    public const int SIGNUP_CODE = 3;
    public const int LOGOUT_CODE = 4;
    public const int GET_ROOMS_CODE = 5;
    public const int GET_PLAYERS_CODE = 6;
    public const int JOIN_ROOM_CODE = 7;
    public const int CREATE_ROOM_CODE = 8;
    public const int HIGH_SCORE_CODE = 9;
    public const int PERSONAL_STATS_CODE = 10;
    public const int CLOSE_ROOM_CODE = 11;
    public const int START_GAME_CODE = 12;
    public const int GET_ROOM_STATE_CODE = 13;
    public const int LEAVE_ROOM_CODE = 14;
    public const int GET_RESULTS_CODE = 15;
    public const int SUBMIT_ANS_CODE = 16;
    public const int GET_QUESTION_RESP_CODE = 17;
    public const int LEAVE_GAME_CODE = 18;


    public const int HEADERS_LENGTH = 5;

    public const int FAILURE_STATUS = 0;
    public const int SUCCESS_STATUS = 1;

    public const int REFRESH_INTERVAL_MS = 3000;
    public const int NOT_FOUND = -1;
    public const int MAX_NUM_OF_QUESTIONS = 20;
    public const int SECONDS_TO_MS = 1000;
    public const int ERROR_ID = -1;
    public const int NUM_OF_ANSWERS = 4;
}

namespace GuiClient
{
    public class Question
    {
        public string question;
        public string[] answers;
    }

    public class PlayerResult
    {
        public string username;
        public int correctAnswerCount;
        public int wrongAnswerCount;
        public int averageAnswerTime;
        //grade = (correctAnswerCount / averageAnswerTime) + 1
        public int grade;
    }

    public class Communicator
    {
        private TcpClient _client;
        private IPEndPoint _serverEndPoint;
        private NetworkStream _clientStream;

        public Communicator()
        {
            byte[] _buffer = new byte[Const.MAX_BUFFER_SIZE];

            _client = new TcpClient();
            _serverEndPoint = new IPEndPoint(IPAddress.Parse(Const.SERVER_IP), Const.SERVER_PORT);
            _client.Connect(_serverEndPoint);
            _clientStream = _client.GetStream();

            _clientStream.Read(_buffer, 0, Const.MAX_BUFFER_SIZE);

            if (!Encoding.Default.GetString(_buffer).Substring(0, Const.OPENING_MESSAGE.Length).Equals(Const.OPENING_MESSAGE))
                throw new Exception("Invalid opening message from server:\n" + Encoding.Default.GetString(_buffer).Substring(0, Const.OPENING_MESSAGE.Length));
        }

        private Message SendToServer(Message msg)
        {
            try
            {
                byte[] _buffer = new byte[Const.MAX_BUFFER_SIZE];
                _buffer = new ASCIIEncoding().GetBytes(msg.ToString());
                _clientStream.Write(_buffer, 0, _buffer.Length);
                _clientStream.Flush();

                _buffer = new byte[Const.MAX_BUFFER_SIZE];
                _clientStream.Read(_buffer, 0, Const.MAX_BUFFER_SIZE);
                Message resp = new Message(Encoding.Default.GetString(_buffer));

                if (resp.GetCode() == Const.ERROR_CODE)
                    throw new Exception("Error! " + resp.GetData()["message"]);
                return resp;

            }
            catch (System.IO.IOException ex)
            {
                throw new NoDataToReadException(ex.Message);
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        public bool Login(string username, string password)
        {
            Message loginMessage = new Message(Const.LOGIN_CODE,
                new Dictionary<string, string> { { "username", username }, { "password", password } });
            Message loginResponse = SendToServer(loginMessage);

            return loginResponse.GetData()["status"] == Const.SUCCESS_STATUS.ToString();
        }

        public bool Signup(string username, string password, string email)
        {
            byte[] _buffer = new byte[Const.MAX_BUFFER_SIZE];

            Message signupMessage = new Message(Const.SIGNUP_CODE,
                new Dictionary<string, string> { { "username", username }, { "password", password }, { "email", email } });

            Message signupResponse = SendToServer(signupMessage);
            if (signupResponse.GetData()["status"] == Const.FAILURE_STATUS.ToString())
                return false;

            return Login(username, password);
        }

        public void Close()
        {
            _client.Close();

        }

        public bool CreateRoom(string name, string maxUsers, string questionsCount, string answerTime)
        {
            Message createRoomMessage = new Message(Const.CREATE_ROOM_CODE, new Dictionary<string, string> { { "roomName", name },
                { "maxUsers", maxUsers }, { "questionCount", questionsCount }, { "answerTimeout", answerTime } });

            Message createRoomResponse = SendToServer(createRoomMessage);

            return createRoomResponse.GetData()["status"] == Const.SUCCESS_STATUS.ToString();
        }

        public string[] GetPlayersInRoom(string roomId)
        {
            Message getPlayersMessage = new Message(Const.GET_PLAYERS_CODE,
                new Dictionary<string, string> { { "RoomId", roomId } });

            Message getPlayersResponse = SendToServer(getPlayersMessage);

            return getPlayersResponse.GetData()["PlayersInRoom"].Split(Const.LIST_SEPERATOR);
        }
        public string[] GetUserStatistics()
        {
            Message getStatisticsMessage = new Message(Const.PERSONAL_STATS_CODE,
                new Dictionary<string, string> { });

            Message getStatisticsResponse = SendToServer(getStatisticsMessage);

            return getStatisticsResponse.GetData()["UserStatistics"].Split(Const.LIST_SEPERATOR);
        }
        public string[] GetTopRatedUsers()
        {
            Message getTopRatedUsersMessage = new Message(Const.HIGH_SCORE_CODE,
                new Dictionary<string, string> { });

            Message getTopRatedUsersResponse = SendToServer(getTopRatedUsersMessage);

            return getTopRatedUsersResponse.GetData()["HighScores"].Split(Const.LIST_SEPERATOR);
        }

        public Dictionary<string, string> GetRooms()
        {
            Message getRoomsMessage = new Message(Const.GET_ROOMS_CODE, new Dictionary<string, string> { });
            Message getRoomsResponse = SendToServer(getRoomsMessage);
            return getRoomsResponse.GetData();
        }

        public bool JoinRoom(string roomId)
        {
            Message joinRoomMessage = new Message(Const.JOIN_ROOM_CODE, new Dictionary<string, string> {
                { "roomId", roomId }});
            Message joinRoomResponse = SendToServer(joinRoomMessage);
            return joinRoomResponse.GetData()["status"] == Const.SUCCESS_STATUS.ToString();
        }

        public RoomData GetRoomData()
        {
            try
            {
                Message getUsersInRoomMessage = new Message(Const.GET_ROOM_STATE_CODE,
                    new Dictionary<string, string> { });

                Message getUsersInRoomResponse = SendToServer(getUsersInRoomMessage);

                if (getUsersInRoomResponse.GetCode() == Const.START_GAME_CODE)
                    throw new GameStartedException();
                if (getUsersInRoomResponse.GetCode() == Const.LEAVE_ROOM_CODE)
                    throw new Exception("room closed");

                RoomData roomData = new RoomData();
                roomData.useres = getUsersInRoomResponse.GetData()["Players"].Split(Const.LIST_SEPERATOR);
                roomData.questionCount = int.Parse(getUsersInRoomResponse.GetData()["QuestionCount"]);
                roomData.answerTimeout = int.Parse(getUsersInRoomResponse.GetData()["AnswerTimeout"]);
                return roomData;
            }
            catch (GameStartedException ex)
            {
                throw ex;
            }
            catch (Exception ex)
            {
                if (ex.Message.Equals("Error! Room not found"))
                    throw new Exception("room closed");

                throw ex;
            }
        }
        public bool LeaveRoom(bool isAdmin)
        {
            Message leaveRoomMessage = null;

            if (isAdmin)
                leaveRoomMessage = new Message(Const.CLOSE_ROOM_CODE,
                    new Dictionary<string, string> { });
            else
                leaveRoomMessage = new Message(Const.LEAVE_ROOM_CODE,
                    new Dictionary<string, string> { });

            Message leaveRoomResponse = SendToServer(leaveRoomMessage);

            return leaveRoomResponse.GetData()["status"] == Const.SUCCESS_STATUS.ToString();
        }
        public bool StartGame()
        {
            Message startGameMessage = new Message(Const.START_GAME_CODE, new Dictionary<string, string> { });

            Message startGameResponse = SendToServer(startGameMessage);

            return startGameResponse.GetData()["status"] == Const.SUCCESS_STATUS.ToString();
        }

        public Question GetQuestion()
        {
            Message request = new Message(Const.GET_QUESTION_RESP_CODE, new Dictionary<string, string> { });
            Message response = SendToServer(request);

            while (true)
                try
                {
                    Question question = new Question
                    {
                        question = response.GetData()["Question"],
                        answers = new string[Const.NUM_OF_ANSWERS]
                    };
                    question.answers[0] = response.GetData()["Ans1"];
                    question.answers[1] = response.GetData()["Ans2"];
                    question.answers[2] = response.GetData()["Ans3"];
                    question.answers[3] = response.GetData()["Ans4"];

                    return question;
                }
                catch (Exception)
                {
                    byte[] _buffer = new byte[Const.MAX_BUFFER_SIZE];
                    _clientStream.Read(_buffer, 0, Const.MAX_BUFFER_SIZE);
                    response = new Message(Encoding.Default.GetString(_buffer));
                }
        }

        //return correct answer id
        public string SubmitAnswer(string answer)
        {
            Message request = new Message(Const.SUBMIT_ANS_CODE, new Dictionary<string, string> {
                { "answer", answer}
            });
            Message response = SendToServer(request);

            while (true)
                try
                {
                    if (int.Parse(response.GetData()["status"]) == Const.TIMEOUT_CODE)
                        throw new TimeoutException();

                    return response.GetData()["CorrectAns"];
                }
                catch (Exception)
                {
                    byte[] _buffer = new byte[Const.MAX_BUFFER_SIZE];
                    _clientStream.Read(_buffer, 0, Const.MAX_BUFFER_SIZE);
                    response = new Message(Encoding.Default.GetString(_buffer));
                }
        }

        public List<PlayerResult> GetResults()
        {
            Message request = new Message(Const.GET_RESULTS_CODE, new Dictionary<string, string> { });
            Message response = SendToServer(request);

            List<PlayerResult> results = new List<PlayerResult>();
            foreach (KeyValuePair<string, string> resultAsPair in response.GetData())
            {
                if (resultAsPair.Key.Equals("status"))
                    continue;
                Dictionary<string, string> result = JsonConvert.DeserializeObject<Dictionary<string, string>>(resultAsPair.Value);
                PlayerResult playerResult = new PlayerResult
                {
                    username = resultAsPair.Key,
                    correctAnswerCount = int.Parse(result["CorrectAnswerCount"]),
                    wrongAnswerCount = int.Parse(result["WrongAnswerCount"]),
                    averageAnswerTime = int.Parse(result["AverageAnswerTime"])
                };
                playerResult.grade = (playerResult.correctAnswerCount / playerResult.averageAnswerTime + 1); //+1 because first second is counted

                results.Add(playerResult);
            }

            return results;
        }

        public void LeaveGame() {
            Message request = new Message(Const.LEAVE_GAME_CODE, new Dictionary<string, string> { });
            SendToServer(request);
		}
    }
}
