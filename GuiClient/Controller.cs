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
            MainMenu mainMenu = new MainMenu(_communicator, this);
            Controls.Add(mainMenu);
            mainMenu.BringToFront();
        }

        public void ShowLoginScreen()
        {
            Controls.Clear();
            LoginScreen loginAndSignup = new LoginScreen(_communicator, this);
            Controls.Add(loginAndSignup);
            loginAndSignup.BringToFront();
        }

        public void ShowCreateRoom()
        {
            Controls.Clear();
            CreateRoom createRoom = new CreateRoom(_communicator, this);
            Controls.Add(createRoom);
            createRoom.BringToFront();
            ShowHomeBtn();
        }
        public void ShowStatistics()
        {
            Controls.Clear();
            Statistics statistics = new Statistics(_communicator, this);
            Controls.Add(statistics);
            statistics.BringToFront();
            ShowHomeBtn();
        }

        public void ShowJoinRoom() {
            Controls.Clear();
            JoinRoom joinRoom = new JoinRoom(_communicator, this);
            Controls.Add(joinRoom);
            joinRoom.BringToFront();
            ShowHomeBtn();
        }

        public void ResetCommunicator()
        {
            try {
                if (_communicator!=null)
                    _communicator.Close();
                _communicator = new Communicator();
                ShowLoginScreen();
            }
            catch (Exception ex) {
                //connection error
                ShowConnectionError(ex.Message);
            }
        }

        public void ShowHomeBtn() {
            Controls.Add(homeButton);
            homeButton.BringToFront();
        }

        private void Controller_Load(object sender, EventArgs e)
        {
            try
            {
                _communicator = new Communicator();
                ShowLoginScreen();
            }
            catch (Exception ex)
            {
                //connection error
                ShowConnectionError(ex.Message);
            }
        }

		private void homeButton_Click(object sender, EventArgs e) {
            ShowMainMenu();
		}
	}
}
