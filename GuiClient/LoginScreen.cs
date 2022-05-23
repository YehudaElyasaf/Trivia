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
    public partial class LoginScreen : UserControl
    {
        private Communicator _communicator;
        private Controller _controller;
        public LoginScreen(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
        }

        private void LoginScreen_Load(object sender, EventArgs e)
        {

        }

        private void loginButton_Click_1(object sender, EventArgs e)
        {
            bool didLoginSucceed = _communicator.Login(loginUsername.Text, loginPassword.Text);
            if (didLoginSucceed)
                _controller.ShowMainMenu();
            else
                MessageBox.Show("Login failed");
        }

        private void signupButton_Click_1(object sender, EventArgs e)
        {

            bool didSignupSucceed = _communicator.Signup(signupUsername.Text, signupPassword.Text, signupMail.Text);
            if (didSignupSucceed)
                _controller.ShowMainMenu();
            else
                MessageBox.Show("Signup failed");
        }
    }
}
