﻿namespace MAIDE
{
    partial class DocumentForm
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
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.map = new MAIDE.UI.CodeMap();
            this.SuspendLayout();
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.Filter = "Assembler|*.asm|All files|*.*";
            // 
            // codeMap1
            // 
            this.map.Dock = System.Windows.Forms.DockStyle.Fill;
            this.map.Location = new System.Drawing.Point(0, 0);
            this.map.Name = "codeMap1";
            this.map.Size = new System.Drawing.Size(292, 266);
            this.map.TabIndex = 0;
            this.map.Text = "codeMap1";
            // 
            // DocumentForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(28)))), ((int)(((byte)(28)))), ((int)(((byte)(29)))));
            this.ClientSize = new System.Drawing.Size(292, 266);
            this.Controls.Add(this.map);
            this.Name = "DocumentForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.DocumentForm_FormClosing);
            this.ResumeLayout(false);

        }

        #endregion
        
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private UI.CodeMap map;
    }
}