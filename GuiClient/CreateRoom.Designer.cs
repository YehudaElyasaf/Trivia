namespace GuiClient
{
    partial class CreateRoom
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.createButton = new System.Windows.Forms.Button();
            this.answerTimeLabel = new System.Windows.Forms.Label();
            this.questionsNumLabel = new System.Windows.Forms.Label();
            this.playersNumLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.answerTime = new System.Windows.Forms.TextBox();
            this.questionsNum = new System.Windows.Forms.TextBox();
            this.playersNum = new System.Windows.Forms.TextBox();
            this.roomName = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // createButton
            // 
            this.createButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.createButton.Location = new System.Drawing.Point(419, 278);
            this.createButton.Name = "createButton";
            this.createButton.Size = new System.Drawing.Size(79, 32);
            this.createButton.TabIndex = 17;
            this.createButton.Text = "Create Room";
            this.createButton.UseVisualStyleBackColor = true;
            this.createButton.Click += new System.EventHandler(this.createButton_Click);
            // 
            // answerTimeLabel
            // 
            this.answerTimeLabel.AutoSize = true;
            this.answerTimeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.answerTimeLabel.Location = new System.Drawing.Point(248, 246);
            this.answerTimeLabel.Name = "answerTimeLabel";
            this.answerTimeLabel.Size = new System.Drawing.Size(144, 24);
            this.answerTimeLabel.TabIndex = 16;
            this.answerTimeLabel.Text = "Time to answer:";
            // 
            // questionsNumLabel
            // 
            this.questionsNumLabel.AutoSize = true;
            this.questionsNumLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.questionsNumLabel.Location = new System.Drawing.Point(198, 211);
            this.questionsNumLabel.Name = "questionsNumLabel";
            this.questionsNumLabel.Size = new System.Drawing.Size(194, 24);
            this.questionsNumLabel.TabIndex = 15;
            this.questionsNumLabel.Text = "Number of Questions:";
            this.questionsNumLabel.Click += new System.EventHandler(this.label3_Click);
            // 
            // playersNumLabel
            // 
            this.playersNumLabel.AutoSize = true;
            this.playersNumLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.playersNumLabel.Location = new System.Drawing.Point(222, 176);
            this.playersNumLabel.Name = "playersNumLabel";
            this.playersNumLabel.Size = new System.Drawing.Size(170, 24);
            this.playersNumLabel.TabIndex = 14;
            this.playersNumLabel.Text = "Number of Players:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.label1.Location = new System.Drawing.Point(270, 141);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(122, 24);
            this.label1.TabIndex = 13;
            this.label1.Text = "Room Name:";
            // 
            // answerTime
            // 
            this.answerTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.answerTime.Location = new System.Drawing.Point(398, 243);
            this.answerTime.Name = "answerTime";
            this.answerTime.Size = new System.Drawing.Size(100, 29);
            this.answerTime.TabIndex = 12;
            // 
            // questionsNum
            // 
            this.questionsNum.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.questionsNum.Location = new System.Drawing.Point(398, 208);
            this.questionsNum.Name = "questionsNum";
            this.questionsNum.Size = new System.Drawing.Size(100, 29);
            this.questionsNum.TabIndex = 11;
            // 
            // playersNum
            // 
            this.playersNum.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.playersNum.Location = new System.Drawing.Point(398, 173);
            this.playersNum.Name = "playersNum";
            this.playersNum.Size = new System.Drawing.Size(100, 29);
            this.playersNum.TabIndex = 10;
            // 
            // roomName
            // 
            this.roomName.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.roomName.Location = new System.Drawing.Point(398, 138);
            this.roomName.Name = "roomName";
            this.roomName.Size = new System.Drawing.Size(100, 29);
            this.roomName.TabIndex = 9;
            // 
            // CreateRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.createButton);
            this.Controls.Add(this.answerTimeLabel);
            this.Controls.Add(this.questionsNumLabel);
            this.Controls.Add(this.playersNumLabel);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.answerTime);
            this.Controls.Add(this.questionsNum);
            this.Controls.Add(this.playersNum);
            this.Controls.Add(this.roomName);
            this.Name = "CreateRoom";
            this.Size = new System.Drawing.Size(816, 489);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button createButton;
        private System.Windows.Forms.Label answerTimeLabel;
        private System.Windows.Forms.Label questionsNumLabel;
        private System.Windows.Forms.Label playersNumLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox answerTime;
        private System.Windows.Forms.TextBox questionsNum;
        private System.Windows.Forms.TextBox playersNum;
        private System.Windows.Forms.TextBox roomName;
    }
}
