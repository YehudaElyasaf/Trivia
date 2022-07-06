using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GuiClient
{
    public partial class RoomData
    {
        public string[] useres;
        public int questionCount;
        public int answerTimeout;
    }

    public partial class WaitingRoom : UserControl
    {
        Communicator _communicator;
        Controller _controller;
        bool _isAdmin;
        RoomData _roomData;

        public bool isAdmin
        {
            get { return _isAdmin; }
        }
        public WaitingRoom(Communicator communicator, Controller controller, bool isAdmin)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
            _isAdmin = isAdmin;

            if (isAdmin)
                startGameButton.Show();
            else
                startGameButton.Hide();
        }

        private void WaitingRoom_Load(object sender, EventArgs e)
        {
            RefreshScreen();
        }

        public void RefreshScreen()
        {
            try
            {
                _roomData = _communicator.GetRoomData();
                if (_roomData.useres.Length > 0)
                    _roomData.useres[0] += " (admin)";

                connectedUsersListLabel.Invoke((MethodInvoker)(() => connectedUsersListLabel.Text = string.Join("\n", _roomData.useres)));
            }
            catch (GameStartedException)
            {
                Invoke((MethodInvoker)(() => _controller.ShowGameRoom(_roomData)));
            }
        }

        private void startGameButton_Click(object sender, EventArgs e)
        {
            _communicator.StartGame();
            _controller.ShowGameRoom(_roomData);
        }
    }
}
