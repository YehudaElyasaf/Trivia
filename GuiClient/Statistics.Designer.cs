namespace GuiClient
{
    partial class Statistics
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
            this.personalStatisticsLabel = new System.Windows.Forms.Label();
            this.highScoresLabel = new System.Windows.Forms.Label();
            this.highScoresUserList = new System.Windows.Forms.Label();
            this.personalStatisticsKeys = new System.Windows.Forms.Label();
            this.personalStatisticsValues = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // personalStatisticsLabel
            // 
            this.personalStatisticsLabel.AutoSize = true;
            this.personalStatisticsLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F);
            this.personalStatisticsLabel.Location = new System.Drawing.Point(45, 67);
            this.personalStatisticsLabel.Name = "personalStatisticsLabel";
            this.personalStatisticsLabel.Size = new System.Drawing.Size(280, 37);
            this.personalStatisticsLabel.TabIndex = 0;
            this.personalStatisticsLabel.Text = "Personal Statistics";
            // 
            // highScoresLabel
            // 
            this.highScoresLabel.AutoSize = true;
            this.highScoresLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F);
            this.highScoresLabel.Location = new System.Drawing.Point(530, 67);
            this.highScoresLabel.Name = "highScoresLabel";
            this.highScoresLabel.Size = new System.Drawing.Size(191, 37);
            this.highScoresLabel.TabIndex = 1;
            this.highScoresLabel.Text = "High Scores";
            // 
            // highScoresUserList
            // 
            this.highScoresUserList.AutoSize = true;
            this.highScoresUserList.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.highScoresUserList.Location = new System.Drawing.Point(533, 114);
            this.highScoresUserList.Name = "highScoresUserList";
            this.highScoresUserList.Size = new System.Drawing.Size(93, 120);
            this.highScoresUserList.TabIndex = 3;
            this.highScoresUserList.Text = "Loading...\r\n\r\nLoading...\r\n\r\nLoading...";
            // 
            // personalStatisticsKeys
            // 
            this.personalStatisticsKeys.AutoSize = true;
            this.personalStatisticsKeys.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.personalStatisticsKeys.Location = new System.Drawing.Point(48, 114);
            this.personalStatisticsKeys.Name = "personalStatisticsKeys";
            this.personalStatisticsKeys.Size = new System.Drawing.Size(203, 168);
            this.personalStatisticsKeys.TabIndex = 4;
            this.personalStatisticsKeys.Text = "Average Answer Time:\r\n\r\nTotal Correct Answers:\r\n\r\nTotal Answers:\r\n\r\nTotal Games:";
            // 
            // personalStatisticsValues
            // 
            this.personalStatisticsValues.AutoSize = true;
            this.personalStatisticsValues.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.personalStatisticsValues.Location = new System.Drawing.Point(257, 114);
            this.personalStatisticsValues.Name = "personalStatisticsValues";
            this.personalStatisticsValues.Size = new System.Drawing.Size(28, 168);
            this.personalStatisticsValues.TabIndex = 5;
            this.personalStatisticsValues.Text = "---\r\n\r\n---\r\n\r\n---\r\n\r\n---";
            this.personalStatisticsValues.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // Statistics
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.personalStatisticsValues);
            this.Controls.Add(this.personalStatisticsKeys);
            this.Controls.Add(this.highScoresUserList);
            this.Controls.Add(this.highScoresLabel);
            this.Controls.Add(this.personalStatisticsLabel);
            this.Name = "Statistics";
            this.Size = new System.Drawing.Size(816, 489);
            this.Load += new System.EventHandler(this.Statistics_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label personalStatisticsLabel;
        private System.Windows.Forms.Label highScoresLabel;
        private System.Windows.Forms.Label highScoresUserList;
        private System.Windows.Forms.Label personalStatisticsKeys;
        private System.Windows.Forms.Label personalStatisticsValues;
    }
}
