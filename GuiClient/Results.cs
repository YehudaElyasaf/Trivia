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
        public Results(Communicator communicator, Controller controller)
        {
            InitializeComponent();
            _communicator = communicator;
            _controller = controller;

            List<PlayerResult> results = GetResults();
            results.OrderBy(o => o.grade);
            
            foreach(PlayerResult result in results)
            {
                ListViewItem item = new ListViewItem(result.username);
                item.SubItems.Add(result.grade.ToString());
                resultsList.Items.Add(item);
            }
        }

        private List<PlayerResult> GetResults()
        {
            while (true)
                try
                {
                    return _controller.GetResults();
                }
                catch (Exception)
                {
                    System.Threading.Thread.Sleep(1 * Const.SECONDS_TO_MS);
                    //try again
                }
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
