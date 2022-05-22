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
    public partial class CreateRoom : Form
    {
        Communicator _communicator;
        public CreateRoom(Communicator communicator)
        {
            _communicator = communicator;
            InitializeComponent();
        }

        private void createButton_Click(object sender, EventArgs e)
        {
            bool worked = _communicator.CreateRoom(roomName.Text, playersNum.Text, questionsNum.Text, answerTime.Text);
        }
    }
}
