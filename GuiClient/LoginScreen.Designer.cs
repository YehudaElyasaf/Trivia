namespace GuiClient
{
    partial class LoginScreen
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
            this.loginLabel = new System.Windows.Forms.Label();
            this.signupLabel = new System.Windows.Forms.Label();
            this.signupButton = new System.Windows.Forms.Button();
            this.signupMail = new System.Windows.Forms.TextBox();
            this.signupPassword = new System.Windows.Forms.TextBox();
            this.signupUsername = new System.Windows.Forms.TextBox();
            this.loginPassword = new System.Windows.Forms.TextBox();
            this.loginUsername = new System.Windows.Forms.TextBox();
            this.loginButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // loginLabel
            // 
            this.loginLabel.AutoSize = true;
            this.loginLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.loginLabel.Location = new System.Drawing.Point(148, 181);
            this.loginLabel.Name = "loginLabel";
            this.loginLabel.Size = new System.Drawing.Size(100, 48);
            this.loginLabel.TabIndex = 17;
            this.loginLabel.Text = "username:\r\npassword:";
            this.loginLabel.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // signupLabel
            // 
            this.signupLabel.AutoSize = true;
            this.signupLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.signupLabel.Location = new System.Drawing.Point(463, 188);
            this.signupLabel.Name = "signupLabel";
            this.signupLabel.Size = new System.Drawing.Size(100, 72);
            this.signupLabel.TabIndex = 16;
            this.signupLabel.Text = "username:\r\npassword:\r\nmail:";
            this.signupLabel.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // signupButton
            // 
            this.signupButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.signupButton.Location = new System.Drawing.Point(594, 279);
            this.signupButton.Name = "signupButton";
            this.signupButton.Size = new System.Drawing.Size(75, 35);
            this.signupButton.TabIndex = 15;
            this.signupButton.Text = "signup";
            this.signupButton.UseVisualStyleBackColor = true;
            // 
            // signupMail
            // 
            this.signupMail.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.signupMail.Location = new System.Drawing.Point(569, 244);
            this.signupMail.Name = "signupMail";
            this.signupMail.Size = new System.Drawing.Size(100, 29);
            this.signupMail.TabIndex = 14;
            // 
            // signupPassword
            // 
            this.signupPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.signupPassword.Location = new System.Drawing.Point(569, 209);
            this.signupPassword.Name = "signupPassword";
            this.signupPassword.Size = new System.Drawing.Size(100, 29);
            this.signupPassword.TabIndex = 13;
            // 
            // signupUsername
            // 
            this.signupUsername.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.signupUsername.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.signupUsername.Location = new System.Drawing.Point(569, 174);
            this.signupUsername.Name = "signupUsername";
            this.signupUsername.Size = new System.Drawing.Size(100, 29);
            this.signupUsername.TabIndex = 12;
            // 
            // loginPassword
            // 
            this.loginPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.loginPassword.Location = new System.Drawing.Point(254, 209);
            this.loginPassword.Name = "loginPassword";
            this.loginPassword.Size = new System.Drawing.Size(100, 29);
            this.loginPassword.TabIndex = 11;
            // 
            // loginUsername
            // 
            this.loginUsername.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.loginUsername.Location = new System.Drawing.Point(254, 174);
            this.loginUsername.Name = "loginUsername";
            this.loginUsername.Size = new System.Drawing.Size(100, 29);
            this.loginUsername.TabIndex = 10;
            // 
            // loginButton
            // 
            this.loginButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F);
            this.loginButton.Location = new System.Drawing.Point(279, 244);
            this.loginButton.Name = "loginButton";
            this.loginButton.Size = new System.Drawing.Size(75, 35);
            this.loginButton.TabIndex = 9;
            this.loginButton.Text = "Login";
            this.loginButton.UseVisualStyleBackColor = true;
            // 
            // LoginScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.loginLabel);
            this.Controls.Add(this.signupLabel);
            this.Controls.Add(this.signupButton);
            this.Controls.Add(this.signupMail);
            this.Controls.Add(this.signupPassword);
            this.Controls.Add(this.signupUsername);
            this.Controls.Add(this.loginPassword);
            this.Controls.Add(this.loginUsername);
            this.Controls.Add(this.loginButton);
            this.Name = "LoginScreen";
            this.Size = new System.Drawing.Size(816, 489);
            this.Load += new System.EventHandler(this.LoginScreen_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label loginLabel;
        private System.Windows.Forms.Label signupLabel;
        private System.Windows.Forms.Button signupButton;
        private System.Windows.Forms.TextBox signupMail;
        private System.Windows.Forms.TextBox signupPassword;
        private System.Windows.Forms.TextBox signupUsername;
        private System.Windows.Forms.TextBox loginPassword;
        private System.Windows.Forms.TextBox loginUsername;
        private System.Windows.Forms.Button loginButton;
    }
}
