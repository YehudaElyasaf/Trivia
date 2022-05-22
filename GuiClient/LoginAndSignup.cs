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

        private void LoginButtonClick(object sender, EventArgs e)
        {
            //login button
            bool didLoginSucceed = _communicator.Login(loginUsername.Text, loginPassword.Text);
            if (didLoginSucceed)
            {
                //show menu
                Controls.Clear();
                MainMenu mainMenu = new MainMenu();
                Controls.Add(mainMenu);
                mainMenu.BringToFront();
            }
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
    }
}
