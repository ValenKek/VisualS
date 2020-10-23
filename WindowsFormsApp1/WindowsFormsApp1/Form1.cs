using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Form calculatingForm = new Form();
        int[] data;
        public Form1()
        {
            InitializeComponent();
           
            TextBox nums = new TextBox
            {               
                Size = new Size(100, 20),
                Location = new Point(70, 75),
                Name = "textBox1",

                 
            };
            Label sumInfo = new Label()
            {
                Location = new Point(0, 100),
                Anchor = AnchorStyles.Left,
                Name = "sumInfo",
                Text = "0",
                AutoSize = true,
               Visible = false,
                Font = new Font("Verdana", 20),
                TextAlign = ContentAlignment.TopLeft

            };
            Label sum = new Label()
            {
                Location = new Point(0,50),
                Anchor = AnchorStyles.Left,
                Name = "sum",
                Text = "0",
                AutoSize = true,
                Visible = false,
                Font = new Font("Verdana", 20),
                TextAlign = ContentAlignment.MiddleCenter

            };
            Button inputData = new Button{
                Size = new Size(100,50),
                Anchor = AnchorStyles.Left,
                Text = "Ввести данные"
            };
            Button showInfo = new Button
            {
                Size = new Size(100, 50),
                Location = new Point(100, 0),
                Anchor = AnchorStyles.Left,
                Text = "Показать информацию"
            };
            //Button findSum = new Button{ 
            //    Size = new Size(100, 35),
            //    Location = new Point(284,220), 
            //    Text="Найти сумму" 
            //};
            Button returnFromF1 = new Button()
            {
                Size = new Size(100,25),
                TextAlign = ContentAlignment.BottomCenter,
                Location = new Point(70, 100),
                Text = "Вернуться"
            };
            Button plusOne = new Button()
            {
                Size = new Size(100, 50),
                TextAlign = ContentAlignment.BottomCenter,
                Location = new Point(70, 125),
                Text = "Увеличить каждое число на 1"
            };
            calculatingForm.Size = new Size(250, 250);

            inputData.Click += button1_Click;
            //findSum.Click += button2_Click;
            returnFromF1.Click += button2_Click;
            plusOne.Click += button3_Click;
            showInfo.Click += button4_Click;
            this.Controls.Add(inputData);
            this.Controls.Add(sum); 
            this.Controls.Add(showInfo);
            this.Controls.Add(sumInfo);
            
            //calculatingForm.Controls.Add(findSum);
            calculatingForm.Controls.Add(nums);
            calculatingForm.Controls.Add(returnFromF1);
            calculatingForm.Controls.Add(plusOne);
        }



        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Visible = false;
            calculatingForm.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            StringBuilder number = new StringBuilder();
            int nums = 0;
            string str = calculatingForm.Controls["textBox1"].Text;
            for (int index = 0, lenght = str.Length; index < lenght; ++index)
            {
                if (Char.Equals(str[index], ' '))
                {
                    if (index - 1 < 0 || Char.Equals(str[index - 1], ' ')) 
                        continue;
                    nums++;
                    continue;
                }
                if (index + 1 == lenght && Char.IsDigit(str[index]))
                    nums++;
            }
            data = new int[nums];
            for (int index = 0, index2 = 0, lenght = str.Length; index < lenght; ++index)
            {
                if (Char.IsDigit(str[index]))             
                    number.Append(str[index]);
                else
                {
                    if (index - 1 < 0 || Char.Equals(str[index - 1], ' '))
                        continue; 
                    data[index2] = Int32.Parse(number.ToString());
                    index2++;
                    number.Clear();
                }
            }
            str = "";
            this.Visible = true;
            calculatingForm.Visible = false;
        }
        private void button3_Click(object sender, EventArgs e)
        {
            StringBuilder tmp = new StringBuilder();
            StringBuilder tmp1 = new StringBuilder();
            int nums = 0;
            string str = calculatingForm.Controls["textBox1"].Text;
            for (int index = 0, index2 = 0, lenght = str.Length; index < lenght; ++index)
            {
                if (Char.IsDigit(str[index]))
                    tmp1.Append(str[index]);
                if (Char.Equals(str[index],' ') || index + 1 == lenght)
                {
                    if (!Equals("", tmp1.ToString()))
                    {
                        tmp.Append((Int32.Parse(tmp1.ToString()) + 1).ToString() + " ");
                        index2++;
                        tmp1.Clear();
                    }
                }
            }
            calculatingForm.Controls["textBox1"].Text = tmp.ToString();
        }
        private void button4_Click(object sender, EventArgs e)
        {
            if (Equals(data, null)) return;
            int sum = 0;
            foreach (var i in data)
            {
                sum += i;
            }
            this.Controls["sum"].Text = sum.ToString();
            this.Controls["sum"].Visible = true;
            this.Controls["sumInfo"].Text = numInfo(sum);
            this.Controls["sumInfo"].Visible = true;
        }
        private string numInfo(int num)
        {

            string answer = "Парное ";
            
            answer += num % 2 == 0 && num != 0 ? "+" : "-";
            answer += "\nПростое ";
            {
                int checker = 0;
                for (int i = 1; i <= num; ++i)
                {
                    if (num % i == 0)
                    {
                        checker++;
                        if (checker == 3) break;
                    };
                }
                answer += (checker == 2 && num != 0 )? "+" : "-";
            }
            answer += "\nНатуральное ";
            answer += (num < 10 && num > 0) ? "+" : "-";
            return answer.ToString();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
