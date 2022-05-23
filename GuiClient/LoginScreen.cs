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
        public LoginScreen(Controller controller, Communicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
        }

        private void LoginScreen_Load(object sender, EventArgs e)
        {

        }

        private void LoginButton_Click(object sender, EventArgs e)
        {
            bool didLoginSucceed = _communicator.Login(loginUsername.Text, loginPassword.Text);
            if (didLoginSucceed)
                _controller.showMainMenu();
            else
                MessageBox.Show("Login failed");
        }
        private void signupButton_Click(object sender, EventArgs e)
        {
            bool didSignupSucceed = _communicator.Signup(signupUsername.Text, signupPassword.Text, signupMail.Text);
            if (didSignupSucceed)
                _controller.showMainMenu();
            else
                MessageBox.Show("Signup failed");
        }
    }
}
