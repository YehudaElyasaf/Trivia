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
    public partial class Controller : Form
    {
        Communicator _communicator;

        public Controller()
        {
            InitializeComponent();
            _communicator = new Communicator();
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
            CreateRoom createRoom = new CreateRoom(_communicator);
            Controls.Add(createRoom);
            createRoom.BringToFront();
        }

        public void ResetCommunicator()
        {
            _communicator.Close();
            _communicator = new Communicator();
        }

        private void Controller_Load(object sender, EventArgs e)
        {
            ShowLoginScreen();
        }
    }
}
