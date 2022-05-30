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
    public partial class WaitingRoom : UserControl
    {
        Communicator _communicator;
        Controller _controller;
        public WaitingRoom(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
        }

        private void WaitingRoom_Load(object sender, EventArgs e)
        {
            RefreshScreen();
        }

        public void RefreshScreen()
        {
            string[] usersInRoom = _communicator.GetUsersInRoom();
            connectedUsersLabel.Text = string.Join("\n", usersInRoom);
        }
    }
}
