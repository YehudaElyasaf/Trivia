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

            try
            {
                if (!int.TryParse(playersNum.Text, out int numOfPlayers) ||
                    !int.TryParse(questionsNum.Text, out int numOfQuestions) ||
                    !int.TryParse(answerTime.Text, out int timeToAnswer))
                {
                    //one of the fields is not an integer
                    playersNum.Text = "";
                    questionsNum.Text = "";
                    answerTime.Text = "";
                    throw new Exception(playersNumLabel.Text + ", " + questionsNumLabel.Text + " and " + answerTimeLabel.Text + " must be integers");
                }
                if (numOfPlayers < 1)
                    throw new Exception("Room must have a least one player");
                if (numOfQuestions < 1 || numOfQuestions > Const.MAX_NUM_OF_QUESTIONS)
                    throw new Exception("Room must have between 1 to " + Const.MAX_NUM_OF_QUESTIONS + " questions");
                if (timeToAnswer < 1)
                    throw new Exception("Time to answer must be at least one");


                bool worked = _communicator.CreateRoom(roomName.Text, playersNum.Text, questionsNum.Text, answerTime.Text);
                if (worked)
                    //create room as admin
                    _controller.ShowWaitingRoom(true);
                else
                    MessageBox.Show("Error");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void CreateRoom_Load(object sender, EventArgs e)
        {

        }
    }
}
