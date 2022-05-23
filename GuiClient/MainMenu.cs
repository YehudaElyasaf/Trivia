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
    public partial class MainMenu : UserControl
    {
        Communicator _communicator;
        LoginAndSignup _previousLoginAndSignup;
        public MainMenu(Communicator communicator, LoginAndSignup previousLoginAndSignup)
        {
            InitializeComponent();
            _communicator = communicator;
            _previousLoginAndSignup = previousLoginAndSignup;
        }

        private void MainMenu_Load(object sender, EventArgs e)
        {

        }

        private void createRoomButton_Click(object sender, EventArgs e)
        {
            (new CreateRoom(_communicator)).Show();
            Hide();
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            _communicator.Close();
            _previousLoginAndSignup.Hide();
            (new LoginAndSignup()).Show();
        }
    }
}
