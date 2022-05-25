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
    public partial class ConnectionError : UserControl
    {
        Controller _controller;
        public ConnectionError(string errorMessage, Controller controller)
        {
            InitializeComponent();
            errorDetailsLabel.Text = errorMessage;
            _controller = controller;
        }

        private void ConnectionError_Load(object sender, EventArgs e)
        {

        }

        private void reconnectButton_Click(object sender, EventArgs e)
        {
            _controller.ResetCommunicator();
        }
    }
}
