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
    public partial class MainMenu : UserControl
    {
        Communicator _communicator;
        Controller _controller;
        public MainMenu(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
        }

        private void MainMenu_Load(object sender, EventArgs e)
        {

        }

        private void createRoomButton_Click(object sender, EventArgs e)
        {
            _controller.ShowCreateRoom();
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            _controller.ResetCommunicator();
        }
    }
}
