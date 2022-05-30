namespace GuiClient
{
    partial class WaitingRoom
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
            this.waitingRoomLabel = new System.Windows.Forms.Label();
            this.connectedUsersLabel = new System.Windows.Forms.Label();
            this.connectedUsersListLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // waitingRoomLabel
            // 
            this.waitingRoomLabel.AutoSize = true;
            this.waitingRoomLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 36F);
            this.waitingRoomLabel.Location = new System.Drawing.Point(129, 31);
            this.waitingRoomLabel.Name = "waitingRoomLabel";
            this.waitingRoomLabel.Size = new System.Drawing.Size(582, 55);
            this.waitingRoomLabel.TabIndex = 0;
            this.waitingRoomLabel.Text = "Waiting for other players...";
            // 
            // connectedUsersLabel
            // 
            this.connectedUsersLabel.AutoSize = true;
            this.connectedUsersLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F);
            this.connectedUsersLabel.Location = new System.Drawing.Point(133, 122);
            this.connectedUsersLabel.Name = "connectedUsersLabel";
            this.connectedUsersLabel.Size = new System.Drawing.Size(233, 31);
            this.connectedUsersLabel.TabIndex = 1;
            this.connectedUsersLabel.Text = "Connected Users:";
            // 
            // connectedUsersListLabel
            // 
            this.connectedUsersListLabel.AutoSize = true;
            this.connectedUsersListLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            this.connectedUsersListLabel.Location = new System.Drawing.Point(372, 122);
            this.connectedUsersListLabel.Name = "connectedUsersListLabel";
            this.connectedUsersListLabel.Size = new System.Drawing.Size(54, 104);
            this.connectedUsersListLabel.TabIndex = 2;
            this.connectedUsersListLabel.Text = "------\r\n------\r\n------\r\n------";
            // 
            // WaitingRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.connectedUsersListLabel);
            this.Controls.Add(this.connectedUsersLabel);
            this.Controls.Add(this.waitingRoomLabel);
            this.Name = "WaitingRoom";
            this.Size = new System.Drawing.Size(816, 489);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label waitingRoomLabel;
        private System.Windows.Forms.Label connectedUsersLabel;
        private System.Windows.Forms.Label connectedUsersListLabel;
    }
}
