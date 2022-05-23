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
        }

        public void ShowMainMenu()
        {
            Controls.Clear();
            MainMenu mainMenu = new MainMenu(_communicator);
            Controls.Add(mainMenu);
            mainMenu.BringToFront();
        }

        public void ShowLoginAndSignup()
        {
            Controls.Clear();
            LoginAndSignup loginAndSignup = new LoginAndSignup(_communicator);
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

        private void Controller_Load(object sender, EventArgs e)
        {
            ShowLoginAndSignup();
        }
    }
}
