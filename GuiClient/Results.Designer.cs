namespace GuiClient
{
    partial class Results
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
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem("");
            this.waitingLabel = new System.Windows.Forms.Label();
            this.username = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.grade = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.resultsList = new System.Windows.Forms.ListView();
            this.SuspendLayout();
            // 
            // waitingLabel
            // 
            this.waitingLabel.AutoSize = true;
            this.waitingLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F);
            this.waitingLabel.Location = new System.Drawing.Point(218, 448);
            this.waitingLabel.Name = "waitingLabel";
            this.waitingLabel.Size = new System.Drawing.Size(388, 31);
            this.waitingLabel.TabIndex = 0;
            this.waitingLabel.Text = "Waiting to all players to finish...";
            // 
            // username
            // 
            this.username.Text = "username";
            this.username.Width = 367;
            // 
            // grade
            // 
            this.grade.Text = "grade";
            this.grade.Width = 365;
            // 
            // resultsList
            // 
            this.resultsList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.username,
            this.grade});
            this.resultsList.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            this.resultsList.HideSelection = false;
            this.resultsList.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1});
            this.resultsList.Location = new System.Drawing.Point(74, 3);
            this.resultsList.Name = "resultsList";
            this.resultsList.Size = new System.Drawing.Size(742, 483);
            this.resultsList.TabIndex = 1;
            this.resultsList.UseCompatibleStateImageBehavior = false;
            this.resultsList.View = System.Windows.Forms.View.Details;
            this.resultsList.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged);
            // 
            // Results
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.resultsList);
            this.Controls.Add(this.waitingLabel);
            this.Name = "Results";
            this.Size = new System.Drawing.Size(816, 489);
            this.Load += new System.EventHandler(this.Results_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label waitingLabel;
        private System.Windows.Forms.ColumnHeader username;
        private System.Windows.Forms.ColumnHeader grade;
        private System.Windows.Forms.ListView resultsList;
    }
}
