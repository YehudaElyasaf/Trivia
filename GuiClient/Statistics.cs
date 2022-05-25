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
    public partial class Statistics : UserControl
    {
        private Communicator _communicator;
        private Controller _controller;
        public Statistics(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
        }

        private void Statistics_Load(object sender, EventArgs e)
        {
            string[] statistics = _communicator.GetUserStatistics();
            personalStatisticsValues.Text = string.Join("\n\n", statistics);

            string[] topRatedUsers = _communicator.GetTopRatedUsers();
            string topRatedUsersList = "";
            for (int i = 1; i<=topRatedUsers.Length; i++)
                topRatedUsersList += i + ". " + topRatedUsers[i-1] + "\n\n";
            highScoresUserList.Text = topRatedUsersList;
        }
    }
}
