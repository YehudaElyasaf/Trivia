namespace GuiClient
{
    partial class GameRoom
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
            this.answer1Button = new System.Windows.Forms.Button();
            this.answer2Button = new System.Windows.Forms.Button();
            this.answer3Button = new System.Windows.Forms.Button();
            this.answer4Button = new System.Windows.Forms.Button();
            this.questionsLeftLabel = new System.Windows.Forms.Label();
            this.correctAnswersLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.questionTextTextbox = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // answer1Button
            // 
            this.answer1Button.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F);
            this.answer1Button.Location = new System.Drawing.Point(0, 209);
            this.answer1Button.Name = "answer1Button";
            this.answer1Button.Size = new System.Drawing.Size(408, 140);
            this.answer1Button.TabIndex = 0;
            this.answer1Button.Text = "Answer 1";
            this.answer1Button.UseVisualStyleBackColor = true;
            this.answer1Button.Click += new System.EventHandler(this.answer1Button_Click);
            // 
            // answer2Button
            // 
            this.answer2Button.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F);
            this.answer2Button.Location = new System.Drawing.Point(408, 209);
            this.answer2Button.Name = "answer2Button";
            this.answer2Button.Size = new System.Drawing.Size(408, 140);
            this.answer2Button.TabIndex = 1;
            this.answer2Button.Text = "Answer 2";
            this.answer2Button.UseVisualStyleBackColor = true;
            // 
            // answer3Button
            // 
            this.answer3Button.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F);
            this.answer3Button.Location = new System.Drawing.Point(0, 349);
            this.answer3Button.Name = "answer3Button";
            this.answer3Button.Size = new System.Drawing.Size(408, 140);
            this.answer3Button.TabIndex = 2;
            this.answer3Button.Text = "Answer 3";
            this.answer3Button.UseVisualStyleBackColor = true;
            // 
            // answer4Button
            // 
            this.answer4Button.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F);
            this.answer4Button.Location = new System.Drawing.Point(408, 349);
            this.answer4Button.Name = "answer4Button";
            this.answer4Button.Size = new System.Drawing.Size(408, 140);
            this.answer4Button.TabIndex = 3;
            this.answer4Button.Text = "Answer 4";
            this.answer4Button.UseVisualStyleBackColor = true;
            // 
            // questionsLeftLabel
            // 
            this.questionsLeftLabel.AutoSize = true;
            this.questionsLeftLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.questionsLeftLabel.Location = new System.Drawing.Point(775, 78);
            this.questionsLeftLabel.Name = "questionsLeftLabel";
            this.questionsLeftLabel.Size = new System.Drawing.Size(30, 24);
            this.questionsLeftLabel.TabIndex = 5;
            this.questionsLeftLabel.Text = "00";
            this.questionsLeftLabel.Click += new System.EventHandler(this.questionsRemainingLabel_Click);
            // 
            // correctAnswersLabel
            // 
            this.correctAnswersLabel.AutoSize = true;
            this.correctAnswersLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.correctAnswersLabel.Location = new System.Drawing.Point(775, 49);
            this.correctAnswersLabel.Name = "correctAnswersLabel";
            this.correctAnswersLabel.Size = new System.Drawing.Size(30, 24);
            this.correctAnswersLabel.TabIndex = 6;
            this.correctAnswersLabel.Text = "00";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.label1.Location = new System.Drawing.Point(636, 78);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(139, 24);
            this.label1.TabIndex = 7;
            this.label1.Text = "Questions Left: ";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopRight;
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.label2.Location = new System.Drawing.Point(616, 49);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(164, 24);
            this.label2.TabIndex = 8;
            this.label2.Text = "Correct Answers:  ";
            this.label2.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 26F);
            this.label3.Location = new System.Drawing.Point(686, 102);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 39);
            this.label3.TabIndex = 9;
            this.label3.Text = "--:--";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // questionTextTextbox
            // 
            this.questionTextTextbox.BackColor = System.Drawing.SystemColors.Control;
            this.questionTextTextbox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.questionTextTextbox.Cursor = System.Windows.Forms.Cursors.Default;
            this.questionTextTextbox.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F);
            this.questionTextTextbox.Location = new System.Drawing.Point(138, 32);
            this.questionTextTextbox.Name = "questionTextTextbox";
            this.questionTextTextbox.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.None;
            this.questionTextTextbox.Size = new System.Drawing.Size(472, 158);
            this.questionTextTextbox.TabIndex = 10;
            this.questionTextTextbox.Text = "Question text here... Question text here... Question text here... Question text h" +
    "ere... Question text here...";
            // 
            // GameRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.questionTextTextbox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.correctAnswersLabel);
            this.Controls.Add(this.questionsLeftLabel);
            this.Controls.Add(this.answer4Button);
            this.Controls.Add(this.answer3Button);
            this.Controls.Add(this.answer2Button);
            this.Controls.Add(this.answer1Button);
            this.Name = "GameRoom";
            this.Size = new System.Drawing.Size(816, 489);
            this.Load += new System.EventHandler(this.GameRoom_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button answer1Button;
        private System.Windows.Forms.Button answer2Button;
        private System.Windows.Forms.Button answer3Button;
        private System.Windows.Forms.Button answer4Button;
        private System.Windows.Forms.Label questionsLeftLabel;
        private System.Windows.Forms.Label correctAnswersLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RichTextBox questionTextTextbox;
    }
}
