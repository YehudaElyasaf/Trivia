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

    public const int HEADERS_LENGTH = 5;

    public const int FAILURE_STATUS = 0;
    public const int SUCCESS_STATUS = 1;
}

namespace GuiClient
{
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
            byte[] _buffer = new byte[Const.MAX_BUFFER_SIZE];
            _buffer = new ASCIIEncoding().GetBytes(msg.ToString());
            _clientStream.Write(_buffer, 0, _buffer.Length);
            _clientStream.Flush();

            _buffer = new byte[Const.MAX_BUFFER_SIZE];
            _clientStream.Read(_buffer, 0, Const.MAX_BUFFER_SIZE);

            Message resp = new Message(Encoding.Default.GetString(_buffer));

            if (resp.GetCode() == Const.ERROR_CODE)
            {
                throw new Exception("Error! " + resp.GetData()["message"]);
            }

            return resp;
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

        public Dictionary<string, string> GetRooms() {
            Message getRoomsMessage = new Message(Const.GET_ROOMS_CODE, new Dictionary<string, string> { });
            Message getRoomsResponse = SendToServer(getRoomsMessage);
            return getRoomsResponse.GetData();
		}

        public bool JoinRoom(string roomId) {
            Message joinRoomMessage = new Message(Const.JOIN_ROOM_CODE, new Dictionary<string, string> {
                { "roomId", roomId }});
            Message joinRoomResponse = SendToServer(joinRoomMessage);
            return joinRoomResponse.GetData()["status"] == Const.SUCCESS_STATUS.ToString();
        }
    }
}
