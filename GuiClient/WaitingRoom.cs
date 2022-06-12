﻿using System;
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
    public partial class WaitingRoom : UserControl
    {
        Communicator _communicator;
        Controller _controller;
        bool _isAdmin;
        public bool isAdmin
        {
            get { return _isAdmin; }
        }
        public WaitingRoom(Communicator communicator, Controller controller, bool isAdmin)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
            _isAdmin = isAdmin;

            if (isAdmin)
                startGameButton.Show();
            else
                startGameButton.Hide();
        }

        private void WaitingRoom_Load(object sender, EventArgs e)
        {
            RefreshScreen();
        }

        public void RefreshScreen()
        {
            try
            {
                string[] usersInRoom = _communicator.GetUsersInRoom();
                if (usersInRoom.Length > 0)
                    usersInRoom[0]+=" (admin)";

                connectedUsersListLabel.Invoke((MethodInvoker)(() => connectedUsersListLabel.Text = string.Join("\n", usersInRoom)));
            }
            catch (GameStartedException ex)
            {
                _controller.ShowGameRoom();
            }
            catch (Exception ex) {
                MessageBox.Show(ex.Message);
                _controller.ShowMainMenu();
            }
        }

        private void startGameButton_Click(object sender, EventArgs e)
        {
            _communicator.StartGame();
            _controller.ShowGameRoom();
        }
    }
}
