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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.CheckedListBox playersList;
            this.roomName = new System.Windows.Forms.TextBox();
            this.nameLabel = new System.Windows.Forms.Label();
            this.TTAnswerLabel = new System.Windows.Forms.Label();
            this.answerTime = new System.Windows.Forms.TextBox();
            this.playersNumLabel = new System.Windows.Forms.Label();
            this.playersNum = new System.Windows.Forms.TextBox();
            this.createButton = new System.Windows.Forms.Button();
            this.questionNumLabel = new System.Windows.Forms.Label();
            this.questionsNum = new System.Windows.Forms.TextBox();
            playersList = new System.Windows.Forms.CheckedListBox();
            this.SuspendLayout();
            // 
            // playersList
            // 
            playersList.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            playersList.FormattingEnabled = true;
            playersList.Location = new System.Drawing.Point(428, 40);
            playersList.Name = "playersList";
            playersList.Size = new System.Drawing.Size(324, 316);
            playersList.TabIndex = 7;
            // 
            // roomName
            // 
            this.roomName.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.roomName.Location = new System.Drawing.Point(251, 137);
            this.roomName.Name = "roomName";
            this.roomName.Size = new System.Drawing.Size(124, 29);
            this.roomName.TabIndex = 0;
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.nameLabel.Location = new System.Drawing.Point(179, 140);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(66, 24);
            this.nameLabel.TabIndex = 1;
            this.nameLabel.Text = "Name:";
            // 
            // TTAnswerLabel
            // 
            this.TTAnswerLabel.AutoSize = true;
            this.TTAnswerLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.TTAnswerLabel.Location = new System.Drawing.Point(12, 175);
            this.TTAnswerLabel.Name = "TTAnswerLabel";
            this.TTAnswerLabel.Size = new System.Drawing.Size(233, 24);
            this.TTAnswerLabel.TabIndex = 3;
            this.TTAnswerLabel.Text = "Time to answer (seconds):";
            // 
            // answerTime
            // 
            this.answerTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.answerTime.Location = new System.Drawing.Point(251, 172);
            this.answerTime.Name = "answerTime";
            this.answerTime.Size = new System.Drawing.Size(124, 29);
            this.answerTime.TabIndex = 2;
            // 
            // playersNumLabel
            // 
            this.playersNumLabel.AutoSize = true;
            this.playersNumLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.playersNumLabel.Location = new System.Drawing.Point(76, 245);
            this.playersNumLabel.Name = "playersNumLabel";
            this.playersNumLabel.Size = new System.Drawing.Size(169, 24);
            this.playersNumLabel.TabIndex = 5;
            this.playersNumLabel.Text = "Number of players:";
            // 
            // playersNum
            // 
            this.playersNum.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.playersNum.Location = new System.Drawing.Point(251, 242);
            this.playersNum.Name = "playersNum";
            this.playersNum.Size = new System.Drawing.Size(124, 29);
            this.playersNum.TabIndex = 4;
            // 
            // createButton
            // 
            this.createButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.createButton.Location = new System.Drawing.Point(300, 277);
            this.createButton.Name = "createButton";
            this.createButton.Size = new System.Drawing.Size(75, 37);
            this.createButton.TabIndex = 6;
            this.createButton.Text = "Create";
            this.createButton.UseVisualStyleBackColor = true;
            this.createButton.Click += new System.EventHandler(this.createButton_Click);
            // 
            // questionNumLabel
            // 
            this.questionNumLabel.AutoSize = true;
            this.questionNumLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.questionNumLabel.Location = new System.Drawing.Point(55, 212);
            this.questionNumLabel.Name = "questionNumLabel";
            this.questionNumLabel.Size = new System.Drawing.Size(190, 24);
            this.questionNumLabel.TabIndex = 9;
            this.questionNumLabel.Text = "Number of questions:";
            this.questionNumLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // questionsNum
            // 
            this.questionsNum.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.questionsNum.Location = new System.Drawing.Point(251, 207);
            this.questionsNum.Name = "questionsNum";
            this.questionsNum.Size = new System.Drawing.Size(124, 29);
            this.questionsNum.TabIndex = 8;
            // 
            // CreateRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.questionNumLabel);
            this.Controls.Add(this.questionsNum);
            this.Controls.Add(playersList);
            this.Controls.Add(this.createButton);
            this.Controls.Add(this.playersNumLabel);
            this.Controls.Add(this.playersNum);
            this.Controls.Add(this.TTAnswerLabel);
            this.Controls.Add(this.answerTime);
            this.Controls.Add(this.nameLabel);
            this.Controls.Add(this.roomName);
            this.Name = "CreateRoom";
            this.Text = "CreateRoom";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox roomName;
        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.Label TTAnswerLabel;
        private System.Windows.Forms.TextBox answerTime;
        private System.Windows.Forms.Label playersNumLabel;
        private System.Windows.Forms.TextBox playersNum;
        private System.Windows.Forms.Button createButton;
        private System.Windows.Forms.Label questionNumLabel;
        private System.Windows.Forms.TextBox questionsNum;
    }
}