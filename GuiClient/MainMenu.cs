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
        public Menu(Communicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
        }

        private void MainMenu_Load(object sender, EventArgs e)
        {

        }

        private void createRoomButton_Click(object sender, EventArgs e)
        {
            (new CreateRoom(_communicator)).Show();
            this.Hide();
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();
        }
    }
}
