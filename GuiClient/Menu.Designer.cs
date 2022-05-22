namespace GuiClient
{
    partial class Menu
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
            this.createRoomButton = new System.Windows.Forms.Button();
            this.joinRoomButton = new System.Windows.Forms.Button();
            this.statsButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // createRoomButton
            // 
            this.createRoomButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.createRoomButton.Location = new System.Drawing.Point(327, 31);
            this.createRoomButton.Name = "createRoomButton";
            this.createRoomButton.Size = new System.Drawing.Size(152, 34);
            this.createRoomButton.TabIndex = 0;
            this.createRoomButton.Text = "Create a Room";
            this.createRoomButton.UseVisualStyleBackColor = true;
            // 
            // joinRoomButton
            // 
            this.joinRoomButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.joinRoomButton.Location = new System.Drawing.Point(327, 141);
            this.joinRoomButton.Name = "joinRoomButton";
            this.joinRoomButton.Size = new System.Drawing.Size(152, 34);
            this.joinRoomButton.TabIndex = 1;
            this.joinRoomButton.Text = "Join a Room";
            this.joinRoomButton.UseVisualStyleBackColor = true;
            // 
            // statsButton
            // 
            this.statsButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.statsButton.Location = new System.Drawing.Point(327, 256);
            this.statsButton.Name = "statsButton";
            this.statsButton.Size = new System.Drawing.Size(152, 34);
            this.statsButton.TabIndex = 2;
            this.statsButton.Text = "Statistics";
            this.statsButton.UseVisualStyleBackColor = true;
            // 
            // exitButton
            // 
            this.exitButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.exitButton.Location = new System.Drawing.Point(327, 366);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(152, 34);
            this.exitButton.TabIndex = 3;
            this.exitButton.Text = "Exit";
            this.exitButton.UseVisualStyleBackColor = true;
            // 
            // Menu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.statsButton);
            this.Controls.Add(this.joinRoomButton);
            this.Controls.Add(this.createRoomButton);
            this.Name = "Menu";
            this.Text = "Menu";
            this.Load += new System.EventHandler(this.Menu_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button createRoomButton;
        private System.Windows.Forms.Button joinRoomButton;
        private System.Windows.Forms.Button statsButton;
        private System.Windows.Forms.Button exitButton;
    }
}