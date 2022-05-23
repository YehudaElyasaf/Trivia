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
            this.reconnectButton = new System.Windows.Forms.Button();
            this.connectionErrorLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // reconnectButton
            // 
            this.reconnectButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.reconnectButton.Location = new System.Drawing.Point(315, 159);
            this.reconnectButton.Name = "reconnectButton";
            this.reconnectButton.Size = new System.Drawing.Size(152, 31);
            this.reconnectButton.TabIndex = 0;
            this.reconnectButton.Text = "Click to reconnect";
            this.reconnectButton.UseVisualStyleBackColor = true;
            // 
            // connectionErrorLabel
            // 
            this.connectionErrorLabel.AutoSize = true;
            this.connectionErrorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F);
            this.connectionErrorLabel.Location = new System.Drawing.Point(241, 127);
            this.connectionErrorLabel.Name = "connectionErrorLabel";
            this.connectionErrorLabel.Size = new System.Drawing.Size(302, 29);
            this.connectionErrorLabel.TabIndex = 1;
            this.connectionErrorLabel.Text = "A connection error occured";
            // 
            // ConnectionError
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.connectionErrorLabel);
            this.Controls.Add(this.reconnectButton);
            this.Name = "ConnectionError";
            this.Size = new System.Drawing.Size(816, 489);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button reconnectButton;
        private System.Windows.Forms.Label connectionErrorLabel;
    }
}
