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
    public partial class CreateRoom : Form
    {
        Communicator _communicator;
        public CreateRoom(Communicator communicator)
        {
            _communicator = communicator;
            InitializeComponent();
        }

        private void createButton_Click(object sender, EventArgs e)
        {
            bool worked = _communicator.CreateRoom(roomName.Text, playersNum.Text, questionsNum.Text, answerTime.Text);
        }

        private void InitializeComponent()
        {
            this.roomName = new System.Windows.Forms.TextBox();
            this.playersNum = new System.Windows.Forms.TextBox();
            this.questionsNum = new System.Windows.Forms.TextBox();
            this.answerTime = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.createButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // roomName
            // 
            this.roomName.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.roomName.Location = new System.Drawing.Point(464, 75);
            this.roomName.Name = "roomName";
            this.roomName.Size = new System.Drawing.Size(100, 29);
            this.roomName.TabIndex = 0;
            // 
            // playersNum
            // 
            this.playersNum.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.playersNum.Location = new System.Drawing.Point(464, 110);
            this.playersNum.Name = "playersNum";
            this.playersNum.Size = new System.Drawing.Size(100, 29);
            this.playersNum.TabIndex = 1;
            // 
            // questionsNum
            // 
            this.questionsNum.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.questionsNum.Location = new System.Drawing.Point(464, 145);
            this.questionsNum.Name = "questionsNum";
            this.questionsNum.Size = new System.Drawing.Size(100, 29);
            this.questionsNum.TabIndex = 2;
            // 
            // answerTime
            // 
            this.answerTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.answerTime.Location = new System.Drawing.Point(464, 180);
            this.answerTime.Name = "answerTime";
            this.answerTime.Size = new System.Drawing.Size(100, 29);
            this.answerTime.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.label1.Location = new System.Drawing.Point(336, 78);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(122, 24);
            this.label1.TabIndex = 4;
            this.label1.Text = "Room Name:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.label2.Location = new System.Drawing.Point(288, 113);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(170, 24);
            this.label2.TabIndex = 5;
            this.label2.Text = "Number of Players:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.label3.Location = new System.Drawing.Point(264, 148);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(194, 24);
            this.label3.TabIndex = 6;
            this.label3.Text = "Number of Questions:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.label4.Location = new System.Drawing.Point(314, 183);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(144, 24);
            this.label4.TabIndex = 7;
            this.label4.Text = "Time to answer:";
            // 
            // createButton
            // 
            this.createButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.createButton.Location = new System.Drawing.Point(485, 215);
            this.createButton.Name = "createButton";
            this.createButton.Size = new System.Drawing.Size(79, 32);
            this.createButton.TabIndex = 8;
            this.createButton.Text = "Create Room";
            this.createButton.UseVisualStyleBackColor = true;
            this.createButton.Click += new System.EventHandler(this.createButton_Click);
            // 
            // CreateRoom
            // 
            this.ClientSize = new System.Drawing.Size(1000, 476);
            this.Controls.Add(this.createButton);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.answerTime);
            this.Controls.Add(this.questionsNum);
            this.Controls.Add(this.playersNum);
            this.Controls.Add(this.roomName);
            this.Name = "CreateRoom";
            this.Load += new System.EventHandler(this.CreateRoom_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void CreateRoom_Load(object sender, EventArgs e)
        {

        }
    }
}
