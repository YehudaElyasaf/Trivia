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
            timeoutLabel.Hide();
        }
        private void getNewQuestion()
        {
            questionsLeftLabel.Text = _questionsLeft.ToString();

            Question question = _communicator.GetQuestion();
            questionTextTextbox.Text = question.question;
            answer1Button.Text = question.answers[0];
            answer2Button.Text = question.answers[1];
            answer3Button.Text = question.answers[2];
            answer4Button.Text = question.answers[3];

            timer.Start();
            timerLabel.Text = _answerTimeout.ToString();
        }
        private void answer1Button_Click(object sender, EventArgs e)
        {
            SubmitAnswer(answer1Button.Text);
        }
        private void answer2Button_Click(object sender, EventArgs e)
        {
            SubmitAnswer(answer2Button.Text);
        }
        private void answer3Button_Click(object sender, EventArgs e)
        {
            SubmitAnswer(answer3Button.Text);
        }
        private void answer4Button_Click(object sender, EventArgs e)
        {
            SubmitAnswer(answer4Button.Text);
        }

        private void SubmitAnswer(string answer)
        {
            timer.Stop();
            wrongAnswerLabel.Hide();
            correctAnswerLabel.Hide();
            timeoutLabel.Hide();

            timer.Interval = 1 * Const.SECONDS_TO_MS;

            try
            {
                string correctAnswer = _communicator.SubmitAnswer(answer);
                if (answer == correctAnswer)
                {
                    correctAnswerLabel.Show();
                    int correctAnswers = int.Parse(correctAnswersLabel.Text);
                    correctAnswersLabel.Text = (correctAnswers + 1).ToString();
                }
                else
                {
                    wrongAnswerLabel.Show();
                }
            }
            catch (TimeoutException)
            {
                timeoutLabel.Show();
            }

            _questionsLeft--;
            if (_questionsLeft == 0)
            {
                //game finished
                System.Threading.Thread.Sleep(1 * Const.SECONDS_TO_MS);
                _controller.ShowResults();
                timer.Stop();
                return;
            }
            getNewQuestion();
        }

        private void TimerTick(Object myObject, EventArgs myEventArgs)
        {
            int timeRemaining = int.Parse(timerLabel.Text);
            timeRemaining--;

            if (timeRemaining < 1)
                SubmitAnswer("");
            else
            {
                timerLabel.Text = timeRemaining.ToString();
            }
        }

        private void questionTextTextbox_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
