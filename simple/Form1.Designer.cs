namespace simple
{
    partial class Form1
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
            this.txtD1 = new System.Windows.Forms.TextBox();
            this.txtCPF = new System.Windows.Forms.TextBox();
            this.txtD2 = new System.Windows.Forms.TextBox();
            this.btnVerifica = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // txtD1
            // 
            this.txtD1.Location = new System.Drawing.Point(249, 49);
            this.txtD1.MaxLength = 1;
            this.txtD1.Name = "txtD1";
            this.txtD1.Size = new System.Drawing.Size(31, 20);
            this.txtD1.TabIndex = 0;
            this.txtD1.Text = "DV1";
            this.txtD1.Click += new System.EventHandler(this.txtD1_Click);
            // 
            // txtCPF
            // 
            this.txtCPF.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            this.txtCPF.HideSelection = false;
            this.txtCPF.Location = new System.Drawing.Point(143, 49);
            this.txtCPF.MaxLength = 9;
            this.txtCPF.Name = "txtCPF";
            this.txtCPF.Size = new System.Drawing.Size(100, 20);
            this.txtCPF.TabIndex = 1;
            this.txtCPF.Text = "CPF";
            this.txtCPF.UseWaitCursor = true;
            this.txtCPF.Click += new System.EventHandler(this.txtCPF_Click);
            this.txtCPF.TextChanged += new System.EventHandler(this.txtCPF_TextChanged);
            // 
            // txtD2
            // 
            this.txtD2.Location = new System.Drawing.Point(290, 49);
            this.txtD2.MaxLength = 1;
            this.txtD2.Name = "txtD2";
            this.txtD2.Size = new System.Drawing.Size(33, 20);
            this.txtD2.TabIndex = 2;
            this.txtD2.Text = "DV2";
            this.txtD2.Click += new System.EventHandler(this.txtD2_Click);
            this.txtD2.TextChanged += new System.EventHandler(this.txtD2_TextChanged);
            // 
            // btnVerifica
            // 
            this.btnVerifica.Location = new System.Drawing.Point(249, 96);
            this.btnVerifica.Name = "btnVerifica";
            this.btnVerifica.Size = new System.Drawing.Size(90, 23);
            this.btnVerifica.TabIndex = 3;
            this.btnVerifica.Text = "Validar";
            this.btnVerifica.UseVisualStyleBackColor = true;
            this.btnVerifica.Click += new System.EventHandler(this.btnVerifica_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.InactiveBorder;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(118, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(206, 25);
            this.label1.TabIndex = 4;
            this.label1.Text = "VALIDAÇÃO DE CPF";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(12, 96);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(170, 18);
            this.label2.TabIndex = 5;
            this.label2.Text = "Trabalho Prof° Gordinho";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.MenuHighlight;
            this.ClientSize = new System.Drawing.Size(403, 131);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnVerifica);
            this.Controls.Add(this.txtD2);
            this.Controls.Add(this.txtCPF);
            this.Controls.Add(this.txtD1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtD1;
        private System.Windows.Forms.TextBox txtCPF;
        private System.Windows.Forms.TextBox txtD2;
        private System.Windows.Forms.Button btnVerifica;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

