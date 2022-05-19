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
}
namespace GuiClient
{
    internal class Communicator
    {
        private TcpClient _client;
        private IPEndPoint _serverEndPoint;
        private NetworkStream _clientStream;
        byte[] buffer;

        public Communicator()
        {
            _client = new TcpClient();
            _serverEndPoint = new IPEndPoint(IPAddress.Parse(Const.SERVER_IP), Const.SERVER_PORT);
            _clientStream = _client.GetStream();

            buffer = new byte[Const.MAX_BUFFER_SIZE];
            _clientStream.Read(buffer, 0, Const.MAX_BUFFER_SIZE);
            if (!Convert.ToBase64String(buffer).Equals(buffer))
                throw new Exception("Invalid opening message from server:\n" + Convert.ToBase64String(buffer));
        }
    }
}
