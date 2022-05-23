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
    public partial class LoginAndSignup : Form
    {
        Communicator _communicator;
        public LoginAndSignup()
        {
            InitializeComponent();
            _communicator = new Communicator();
        }

        private void showMainMenu()
        {
            Controls.Clear();
            MainMenu mainMenu = new MainMenu(_communicator, this);
            Controls.Add(mainMenu);
            mainMenu.BringToFront();
        }
        private void LoginButton_Click(object sender, EventArgs e)
        {
            bool didLoginSucceed = _communicator.Login(loginUsername.Text, loginPassword.Text);
            if (didLoginSucceed)
                showMainMenu();
            else
                MessageBox.Show("Login failed");
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click_2(object sender, EventArgs e)
        {

        }
        private void loginLabel_Click(object sender, EventArgs e)
        {

        }

        private void signupButton_Click(object sender, EventArgs e)
        {
            bool didSignupSucceed = _communicator.Signup(signupUsername.Text, signupPassword.Text, signupMail.Text);
            if (didSignupSucceed)
                showMainMenu();
            else
                MessageBox.Show("Signup failed");
        }
    }
}
