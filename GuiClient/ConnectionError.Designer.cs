namespace GuiClient
{
    partial class ConnectionError
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
            this.connectionErrorLabel = new System.Windows.Forms.Label();
            this.errorDetailsLabel = new System.Windows.Forms.Label();
            this.reconnectButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // connectionErrorLabel
            // 
            this.connectionErrorLabel.AutoSize = true;
            this.connectionErrorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 30F);
            this.connectionErrorLabel.Location = new System.Drawing.Point(61, 83);
            this.connectionErrorLabel.Name = "connectionErrorLabel";
            this.connectionErrorLabel.Size = new System.Drawing.Size(515, 46);
            this.connectionErrorLabel.TabIndex = 1;
            this.connectionErrorLabel.Text = "A connection error occured!";
            // 
            // errorDetailsLabel
            // 
            this.errorDetailsLabel.AutoSize = true;
            this.errorDetailsLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.errorDetailsLabel.Location = new System.Drawing.Point(65, 129);
            this.errorDetailsLabel.Name = "errorDetailsLabel";
            this.errorDetailsLabel.Size = new System.Drawing.Size(154, 20);
            this.errorDetailsLabel.TabIndex = 2;
            this.errorDetailsLabel.Text = "UNKNOWN ERROR";
            // 
            // reconnectButton
            // 
            this.reconnectButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F);
            this.reconnectButton.Location = new System.Drawing.Point(291, 240);
            this.reconnectButton.Name = "reconnectButton";
            this.reconnectButton.Size = new System.Drawing.Size(217, 38);
            this.reconnectButton.TabIndex = 3;
            this.reconnectButton.Text = "Click to reconnect";
            this.reconnectButton.UseVisualStyleBackColor = true;
            this.reconnectButton.Click += new System.EventHandler(this.reconnectButton_Click);
            // 
            // ConnectionError
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.reconnectButton);
            this.Controls.Add(this.errorDetailsLabel);
            this.Controls.Add(this.connectionErrorLabel);
            this.Name = "ConnectionError";
            this.Size = new System.Drawing.Size(816, 489);
            this.Load += new System.EventHandler(this.ConnectionError_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label connectionErrorLabel;
        private System.Windows.Forms.Label errorDetailsLabel;
        private System.Windows.Forms.Button reconnectButton;
    }
}
