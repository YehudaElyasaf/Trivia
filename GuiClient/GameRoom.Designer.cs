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
            this.questionTextTextbox = new System.Windows.Forms.RichTextBox();
            this.answer1Button = new System.Windows.Forms.Button();
            this.answer2Button = new System.Windows.Forms.Button();
            this.answer3Button = new System.Windows.Forms.Button();
            this.answer4Button = new System.Windows.Forms.Button();
            this.questionsLeftLabel = new System.Windows.Forms.Label();
            this.correctAnswersLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.timerLabel = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.wrongAnswerLabel = new System.Windows.Forms.Label();
            this.correctAnswerLabel = new System.Windows.Forms.Label();
            this.timeoutLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // questionTextTextbox
            // 
            this.questionTextTextbox.BackColor = System.Drawing.SystemColors.Control;
            this.questionTextTextbox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.questionTextTextbox.Cursor = System.Windows.Forms.Cursors.Default;
            this.questionTextTextbox.Enabled = false;
            this.questionTextTextbox.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F);
            this.questionTextTextbox.Location = new System.Drawing.Point(138, 32);
            this.questionTextTextbox.Name = "questionTextTextbox";
            this.questionTextTextbox.ReadOnly = true;
            this.questionTextTextbox.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.None;
            this.questionTextTextbox.Size = new System.Drawing.Size(472, 158);
            this.questionTextTextbox.TabIndex = 10;
            this.questionTextTextbox.Text = "Question text here...";
            this.questionTextTextbox.TextChanged += new System.EventHandler(this.questionTextTextbox_TextChanged);
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
            this.answer2Button.Click += new System.EventHandler(this.answer2Button_Click);
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
            this.answer3Button.Click += new System.EventHandler(this.answer3Button_Click);
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
            this.answer4Button.Click += new System.EventHandler(this.answer4Button_Click);
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
            this.label1.Location = new System.Drawing.Point(637, 78);
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
            // timerLabel
            // 
            this.timerLabel.AutoSize = true;
            this.timerLabel.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.timerLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.timerLabel.Location = new System.Drawing.Point(775, 110);
            this.timerLabel.Name = "timerLabel";
            this.timerLabel.Size = new System.Drawing.Size(30, 24);
            this.timerLabel.TabIndex = 9;
            this.timerLabel.Text = "00";
            this.timerLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.label3.Location = new System.Drawing.Point(628, 107);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(146, 24);
            this.label3.TabIndex = 11;
            this.label3.Text = "Time ramaining:";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // wrongAnswerLabel
            // 
            this.wrongAnswerLabel.AutoSize = true;
            this.wrongAnswerLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            this.wrongAnswerLabel.ForeColor = System.Drawing.Color.Red;
            this.wrongAnswerLabel.Location = new System.Drawing.Point(367, 180);
            this.wrongAnswerLabel.Name = "wrongAnswerLabel";
            this.wrongAnswerLabel.Size = new System.Drawing.Size(77, 26);
            this.wrongAnswerLabel.TabIndex = 12;
            this.wrongAnswerLabel.Text = "wrong!";
            // 
            // correctAnswerLabel
            // 
            this.correctAnswerLabel.AutoSize = true;
            this.correctAnswerLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            this.correctAnswerLabel.ForeColor = System.Drawing.Color.ForestGreen;
            this.correctAnswerLabel.Location = new System.Drawing.Point(367, 180);
            this.correctAnswerLabel.Name = "correctAnswerLabel";
            this.correctAnswerLabel.Size = new System.Drawing.Size(84, 26);
            this.correctAnswerLabel.TabIndex = 13;
            this.correctAnswerLabel.Text = "correct!";
            // 
            // timeoutLabel
            // 
            this.timeoutLabel.AutoSize = true;
            this.timeoutLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            this.timeoutLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(64)))), ((int)(((byte)(0)))));
            this.timeoutLabel.Location = new System.Drawing.Point(367, 180);
            this.timeoutLabel.Name = "timeoutLabel";
            this.timeoutLabel.Size = new System.Drawing.Size(90, 26);
            this.timeoutLabel.TabIndex = 14;
            this.timeoutLabel.Text = "timeout!";
            // 
            // GameRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.timeoutLabel);
            this.Controls.Add(this.correctAnswerLabel);
            this.Controls.Add(this.wrongAnswerLabel);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.questionTextTextbox);
            this.Controls.Add(this.timerLabel);
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
        private System.Windows.Forms.RichTextBox questionTextTextbox;
        private System.Windows.Forms.Label timerLabel;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label wrongAnswerLabel;
        private System.Windows.Forms.Label correctAnswerLabel;
        private System.Windows.Forms.Label timeoutLabel;
    }
}
