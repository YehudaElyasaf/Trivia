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
            Controls.Clear();
            _currentScreen = new MainMenu(_communicator, this);
            Controls.Add(_currentScreen);
            _currentScreen.BringToFront();
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
        
        public void ShowWaitingRoom()
        {
            Controls.Clear();
            _currentScreen = new WaitingRoom(_communicator, this);
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
                _autoRefresher.IsBackground= true;
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
            ShowMainMenu();
        }
        private void AutoRefresh()
        {
            while (true)
            {
                Thread.Sleep(Const.REFRESH_INTERVAL_MS);

                if (_currentScreen.GetType() == typeof(JoinRoom))
                    ((JoinRoom)_currentScreen).RefreshScreen();
                if (_currentScreen.GetType() == typeof(WaitingRoom))
                    ((WaitingRoom)_currentScreen).RefreshScreen();
            }
        }
    }
}
