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
    public partial class Results : UserControl
    {
        Communicator _communicator;
        Controller _controller;
        public Results(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;

            while (!tryToGetResults())
                System.Threading.Thread.Sleep(1 * Const.SECONDS_TO_MS);
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
