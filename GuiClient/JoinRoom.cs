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
    public partial class JoinRoom : UserControl
    {
        private Communicator _communicator;
        private Controller _controller;
        private string[] _roomIds;

        public JoinRoom(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
        }

        private void joinButton_Click(object sender, EventArgs e)
        {
            if (roomsList.SelectedIndex == Const.NOT_FOUND)
                //no room was chosen
                return;

            if (_roomIds == null || _roomIds.Length == 0)
            {
                MessageBox.Show("Error! could not find this list's index!");
            }
            else
            {
                try
                {
                    if (_communicator.JoinRoom(_roomIds[roomsList.SelectedIndex]))
                    {
                        //false = not as admin
                        _controller.ShowWaitingRoom(false);
                    }
                    else
                    {
                        MessageBox.Show("Could not join room");
                    }
                }
                catch (Exception)
                {
                    //selected room was closed
                    //do nothing
                }
            }
        }

        private void JoinRoom_Load(object sender, EventArgs e)
        {
            RefreshScreen();
        }

        public void RefreshScreen()
        {
            Dictionary<string, string> rooms = _communicator.GetRooms();
            if (roomsList.Items.Count != 0 &&
                rooms["Rooms"].Split(Const.LIST_SEPERATOR).SequenceEqual(roomsList.Items.Cast<string>()))
                return;

            roomsList.Invoke((MethodInvoker)(() => roomsList.Items.Clear()));
            foreach (string roomName in rooms["Rooms"].Split(Const.LIST_SEPERATOR))
            {
                roomsList.Invoke((MethodInvoker)(() => roomsList.Items.Add(roomName)));
            }

            if (rooms["Ids"] != "")
                _roomIds = rooms["Ids"].Split(Const.LIST_SEPERATOR);
        }

        private void roomsList_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            if (e.NewValue == CheckState.Checked)
                for (int i = 0; i < roomsList.Items.Count; i++)
                    if (e.Index != i)
                        roomsList.SetItemChecked(i, false);
        }
    }
}
