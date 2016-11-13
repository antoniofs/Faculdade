using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace simple
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnVerifica_Click(object sender, EventArgs e)
        {
            string cPF = txtCPF.Text;
            int[] numeros = new int[11];
            int d1 = Convert.ToInt32(txtD1.Text);
            int d2 = Convert.ToInt32(txtD2.Text);
            int i = 0;
            int total = 0;
            int totalD2 = 0;

            for (i = 0; i <= 8; i++)
            {
                numeros[i] = int.Parse(cPF[i].ToString());
            }

            for (i = 0; i <= 8; i++)
            {
                total += numeros[i] * (i + 1);
            }
            total %= 11;
            numeros[9] = total;
            
            for (i = 1; i <= 9; i++)
            {
                totalD2 += numeros[i] * i;
            }
            totalD2 %= 11;
            
            if (totalD2 == d2 && total == d1)
            {
                MessageBox.Show("CPF VALIDO !!!");
            }
            else
            {
                MessageBox.Show("OPS....CPF INVALIDO!!!!!");
            } 

            

        }

        private void txtD2_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtCPF_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void txtCPF_Click(object sender, EventArgs e)
        {
            txtCPF.Clear();
        }

        private void txtD1_Click(object sender, EventArgs e)
        {
            txtD1.Clear();
        }

        private void txtD2_Click(object sender, EventArgs e)
        {
            txtD2.Clear();
        }
    }
}
