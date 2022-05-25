using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GuiClient {
	public partial class JoinRoom : UserControl {
		private Communicator _communicator;
		private Controller _controller;
		private string[] _roomIds;

		public JoinRoom(Communicator communicator, Controller controller) {
			InitializeComponent();
			_communicator = communicator;
			_controller = controller;
		}

		private void joinButton_Click(object sender, EventArgs e) {
			if (_roomIds == null || _roomIds.Length == 0) {
				MessageBox.Show("Error! could not find this list's index!");
			}
			else {
				if (_communicator.JoinRoom(_roomIds[roomsList.SelectedIndex])) {
					_controller.ShowMainMenu();
				}
				else {
					MessageBox.Show("Could not join room");
				}
			}
		}

		private void JoinRoom_Load(object sender, EventArgs e) {
			try {
				Dictionary<string, string> rooms = _communicator.GetRooms();
				roomsList.Items.Clear();
				foreach (string roomName in rooms["Rooms"].Split(Const.LIST_SEPERATOR)) {
					roomsList.Items.Add(roomName);
				}

				if (rooms["Ids"] != "")
					_roomIds = rooms["Ids"].Split(Const.LIST_SEPERATOR);
			}
			catch (Exception ex) {
				MessageBox.Show(ex.Message);
			}
		}
	}
}
