using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace GuiClient
{
    public partial class Controller : Form
    {
        Communicator _communicator;
        UserControl _currentScreen;
        Thread _autoRefresher;

        public Controller()
        {
            InitializeComponent();
        }

        public void ShowConnectionError(string errorMessage)
        {
            Controls.Clear();
            ConnectionError connectionError = new ConnectionError(errorMessage, this);
            Controls.Add(connectionError);
            connectionError.BringToFront();
        }

        public void ShowMainMenu()
        {
            try
            {
                this.Invoke((MethodInvoker)(() => Controls.Clear()));
            }
            catch (NoDataToReadException)
            {
                //do nothing
                //because Communicator::SendToServer didn't get any message from server
            }

            _currentScreen.Invoke((MethodInvoker)(() => _currentScreen = new MainMenu(_communicator, this)));
            this.Invoke((MethodInvoker)(() => Controls.Add(_currentScreen)));
            _currentScreen.Invoke((MethodInvoker)(() => _currentScreen.BringToFront()));
            ShowHomeBtn();
        }
        public void ShowGameRoom(RoomData roomData)
        {
            try
            {
                this.Invoke((MethodInvoker)(() => Controls.Clear()));
            }
            catch (NoDataToReadException)
            {
                //do nothing
                //because Communicator::SendToServer didn't get any message from server
            }

            _currentScreen.Invoke((MethodInvoker)(() => _currentScreen = new GameRoom(_communicator, this, roomData.questionCount, roomData.answerTimeout)));
            this.Invoke((MethodInvoker)(() => Controls.Add(_currentScreen)));
            _currentScreen.Invoke((MethodInvoker)(() => _currentScreen.BringToFront()));
            ShowHomeBtn();
        }

        public void ShowLoginScreen()
        {
            Controls.Clear();
            _currentScreen = new LoginScreen(_communicator, this);
            Controls.Add(_currentScreen);
            _currentScreen.BringToFront();
        }

        public void ShowCreateRoom()
        {
            Controls.Clear();
            _currentScreen= new CreateRoom(_communicator, this);
            Controls.Add(_currentScreen);
            _currentScreen.BringToFront();
            ShowHomeBtn();
        }
        public void ShowStatistics()
        {
            Controls.Clear();
            _currentScreen = new Statistics(_communicator, this);
            Controls.Add(_currentScreen);
            _currentScreen.BringToFront();
            ShowHomeBtn();
        }

        public void ShowJoinRoom()
        {
            Controls.Clear();
            _currentScreen = new JoinRoom(_communicator, this);
            Controls.Add(_currentScreen);
            _currentScreen.BringToFront();
            ShowHomeBtn();
        }

        public void ShowWaitingRoom(bool isAdmin)
        {
            Controls.Clear();
            _currentScreen = new WaitingRoom(_communicator, this, isAdmin);
            Controls.Add(_currentScreen);
            _currentScreen.BringToFront();
            ShowHomeBtn();
        }

        public void ResetCommunicator()
        {
            try
            {
                if (_communicator!=null)
                    _communicator.Close();
                _communicator = new Communicator();
                ShowLoginScreen();
            }
            catch (Exception ex)
            {
                //connection error
                ShowConnectionError(ex.Message);
            }
        }

        public void ShowHomeBtn()
        {
            Controls.Add(homeButton);
            homeButton.BringToFront();
        }

        private void Controller_Load(object sender, EventArgs e)
        {
            try
            {
                _communicator = new Communicator();
                _currentScreen = null;
                ShowLoginScreen();
                _autoRefresher = new Thread(new ThreadStart(AutoRefresh));
                _autoRefresher.IsBackground = true;
                _autoRefresher.Start();
            }
            catch (Exception ex)
            {
                //connection error
                ShowConnectionError(ex.Message);
            }
        }
        private void homeButton_Click(object sender, EventArgs e)
        {
            if (_currentScreen.GetType() == typeof(WaitingRoom))
                _communicator.LeaveRoom(((WaitingRoom)_currentScreen).isAdmin);
            ShowMainMenu();
        }
        private void AutoRefresh()
        {
            while (true)
            {
                Thread.Sleep(Const.REFRESH_INTERVAL_MS);

                if (_currentScreen.GetType() == typeof(JoinRoom))
                    ((JoinRoom)_currentScreen).RefreshScreen();
                else if (_currentScreen.GetType() == typeof(WaitingRoom))
                    ((WaitingRoom)_currentScreen).RefreshScreen();
            }
        }
    }
}
