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

    public const int FAILTURE_STATUS = 0;
    public const int SUCCESS_STATUS = 1;
}
namespace GuiClient
{
    internal class Communicator
    {
        private TcpClient _client;
        private IPEndPoint _serverEndPoint;
        private NetworkStream _clientStream;
        byte[] _buffer;

        public Communicator()
        {
            _client = new TcpClient();
            _serverEndPoint = new IPEndPoint(IPAddress.Parse(Const.SERVER_IP), Const.SERVER_PORT);
            _client.Connect(_serverEndPoint);
            _clientStream = _client.GetStream();

            _buffer = new byte[Const.MAX_BUFFER_SIZE];
            _clientStream.Read(_buffer, 0, Const.MAX_BUFFER_SIZE);
            
            if (!Encoding.Default.GetString(_buffer).Substring(0, Const.OPENING_MESSAGE.Length) .Equals(Const.OPENING_MESSAGE))
                throw new Exception("Invalid opening message from server:\n" + Encoding.Default.GetString(_buffer).Substring(0, Const.OPENING_MESSAGE.Length));
        }

        public bool Login(string username, string password)
        {
            Message loginMessage = new Message(Const.LOGIN_CODE,
                new Dictionary<string, string> {{ "username", username }, {"password", password}});
            _buffer = new ASCIIEncoding().GetBytes(loginMessage.ToString());
            _clientStream.Write(_buffer, 0, _buffer.Length);
            _clientStream.Flush();

            _buffer = new byte[Const.MAX_BUFFER_SIZE];
            _clientStream.Read(_buffer, 0, Const.MAX_BUFFER_SIZE);
            Message loginResponse = new Message(_buffer.ToString());

            return loginResponse.getCode() == Const.SUCCESS_STATUS;
        }
    }
}
