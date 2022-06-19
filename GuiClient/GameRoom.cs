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
        int _answerTimeout;
        int _questionsLeft;
        Timer timer = new Timer();

        public GameRoom(Communicator communicator, Controller controller, int questionCount, int answerTimeout)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
            _answerTimeout = answerTimeout;
            _questionsLeft = questionCount;

            timer.Tick += new EventHandler(TimerTick);
        }

        private void questionsRemainingLabel_Click(object sender, EventArgs e)
        {

        }


        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void GameRoom_Load(object sender, EventArgs e)
        {
            getNewQuestion();

            correctAnswerLabel.Hide();
            wrongAnswerLabel.Hide();
        }
        private void getNewQuestion()
        {
            questionsLeftLabel.Text = _questionsLeft.ToString();

            Question question = _communicator.GetQuestion();
            questionTextTextbox.Text = question.question;
            answer1Button.Text = question.answers[1];
            answer2Button.Text = question.answers[2];
            answer3Button.Text = question.answers[3];
            answer4Button.Text = question.answers[4];
        }
        private void answer1Button_Click(object sender, EventArgs e)
        {
            SubmitAnswer(1);
        }
        private void answer2Button_Click(object sender, EventArgs e)
        {
            SubmitAnswer(2);
        }
        private void answer3Button_Click(object sender, EventArgs e)
        {
            SubmitAnswer(3);
        }
        private void answer4Button_Click(object sender, EventArgs e)
        {
            SubmitAnswer(4);
        }

        private void SubmitAnswer(int answerId)
        {
            timerLabel.Text = _answerTimeout.ToString();
            timer.Interval = 1 * Const.SECONDS_TO_MS;
            timer.Start();

            int correctAnswerId = _communicator.SubmitAnswer(answerId);
            if (answerId == correctAnswerId)
            {
                correctAnswerLabel.Show();
                wrongAnswerLabel.Hide();
            }
            else
            {
                correctAnswerLabel.Hide();
                wrongAnswerLabel.Show();
            }

            _questionsLeft--;
            if (_questionsLeft == 0)
            {
                //game finished
                System.Threading.Thread.Sleep(1 * Const.SECONDS_TO_MS);
                _controller.ShowResults();
            }
            getNewQuestion();
        }

        private void TimerTick(Object myObject, EventArgs myEventArgs)
        {
            int timeRemaining = int.Parse(timerLabel.Text);
            timeRemaining--;

            if (timeRemaining < 1)
                SubmitAnswer(Const.ERROR_ID);
            else
            {
                timerLabel.Text = timeRemaining.ToString();
            }
        }

    }
}
