namespace GuiClient
{
    partial class Controller
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Controller));
            this.homeButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // homeButton
            // 
            this.homeButton.BackColor = System.Drawing.Color.Transparent;
            this.homeButton.Image = ((System.Drawing.Image)(resources.GetObject("homeButton.Image")));
            this.homeButton.Location = new System.Drawing.Point(0, 0);
            this.homeButton.Name = "homeButton";
            this.homeButton.Size = new System.Drawing.Size(50, 50);
            this.homeButton.TabIndex = 0;
            this.homeButton.UseVisualStyleBackColor = false;
            this.homeButton.Click += new System.EventHandler(this.homeButton_Click);
            // 
            // Controller
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(814, 487);
            this.Controls.Add(this.homeButton);
            this.Name = "Controller";
            this.Text = "Controller";
            this.Load += new System.EventHandler(this.Controller_Load);
            this.ResumeLayout(false);

        }

		#endregion

		private System.Windows.Forms.Button homeButton;
	}
}