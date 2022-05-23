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
    public partial class CreateRoom : UserControl
    {
        Communicator _communicator;
        Controller _controller;

        public CreateRoom(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
        }

        private void createButton_Click(object sender, EventArgs e)
        {
            bool worked = _communicator.CreateRoom(roomName.Text, playersNum.Text, questionsNum.Text, answerTime.Text);
            if (worked)
                _controller.ShowMainMenu();
            else
                MessageBox.Show("Error");
        }
    }
}
