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
    public partial class GameRoom : UserControl
    {
        Communicator _communicator;
        Controller _controller;
        int _questionCount;
        int _answerTimeout;
        public GameRoom(Communicator communicator, Controller controller, int questionCount, int answerTimeout)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
            _questionCount = questionCount;
            _answerTimeout = answerTimeout;
        }

        private void questionsRemainingLabel_Click(object sender, EventArgs e)
        {

        }

        private void answer1Button_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void GameRoom_Load(object sender, EventArgs e)
        {
            for (int questionId = 0; questionId < _questionCount; questionId++)
            {

            }
        }
    }
}
