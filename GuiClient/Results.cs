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
    public partial class Results : UserControl
    {
        Communicator _communicator;
        Controller _controller;
        bool _isGameFinished;
        public Results(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;
            _isGameFinished = false;
        }


        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Results_Load(object sender, EventArgs e)
        {
            resultsList.Hide();
            waitingLabel.Show();
        }
        public void RefreshScreen()
        {
            if (_isGameFinished)
                return;

            List<PlayerResult> results = _communicator.GetResults();
            waitingLabel.Hide();
            results.OrderBy(o => o.grade * Const.DESCENDING_ORDER);

            resultsList.Show();
            resultsList.Items.Clear();
            foreach (PlayerResult result in results)
            {
                ListViewItem item = new ListViewItem(result.username);
                item.SubItems.Add(result.grade.ToString());
                resultsList.Items.Add(item);
            }

            _isGameFinished = true;
        }
    }
}
