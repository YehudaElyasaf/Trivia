namespace GuiClient {
	partial class JoinRoom {
		/// <summary> 
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary> 
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Component Designer generated code

		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.roomsList = new System.Windows.Forms.CheckedListBox();
			this.joinButton = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// roomsList
			// 
			this.roomsList.CheckOnClick = true;
			this.roomsList.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
			this.roomsList.FormattingEnabled = true;
			this.roomsList.Location = new System.Drawing.Point(114, 34);
			this.roomsList.Name = "roomsList";
			this.roomsList.Size = new System.Drawing.Size(593, 364);
			this.roomsList.TabIndex = 0;
			this.roomsList.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler(this.roomsList_ItemCheck);
			// 
			// joinButton
			// 
			this.joinButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
			this.joinButton.Location = new System.Drawing.Point(369, 404);
			this.joinButton.Name = "joinButton";
			this.joinButton.Size = new System.Drawing.Size(75, 32);
			this.joinButton.TabIndex = 1;
			this.joinButton.Text = "Join";
			this.joinButton.UseVisualStyleBackColor = true;
			this.joinButton.Click += new System.EventHandler(this.joinButton_Click);
			// 
			// JoinRoom
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.Controls.Add(this.joinButton);
			this.Controls.Add(this.roomsList);
			this.Name = "JoinRoom";
			this.Size = new System.Drawing.Size(816, 489);
			this.Load += new System.EventHandler(this.JoinRoom_Load);
			this.ResumeLayout(false);

		}

		#endregion
		private System.Windows.Forms.Button joinButton;
		private System.Windows.Forms.CheckedListBox roomsList;
	}
}
