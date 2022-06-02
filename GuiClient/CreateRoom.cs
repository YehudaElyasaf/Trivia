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

            if (int.TryParse(playersNum.Text, out int n1) &&
                int.TryParse(questionsNum.Text, out int n2) &&
                int.TryParse(answerTime.Text, out int n3))
                try
                {
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
            else
            {
                //one of the fields is not an integer
                MessageBox.Show(playersNumLabel.Text + ", " + questionsNumLabel.Text + " and " + answerTimeLabel.Text + " must be integers");
                playersNum.Text = "";
                questionsNum.Text = "";
                answerTime.Text = "";
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
