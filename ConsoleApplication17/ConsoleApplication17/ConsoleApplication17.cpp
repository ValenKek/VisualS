using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Massiv
{
	class Program
	{
		//class Body
		//{

		//}
		//struct Human : Body
		//{

		//}
		//struct Woman : Human
		//{

		//}

		struct Jumper
		{
			string secondName;
			string poll;
			int countOfMedales;
			public Jumper(string s, string p, int c)
			{
				this.secondName = s;
				this.poll = p;
				this.countOfMedales = c;
			}
			public Jumper(string s)
			{
				this.secondName = s;
				this.poll = "M";
				this.countOfMedales = 8;
			}
			public override bool Equals(Object obj)
			{
				if ((obj == null) || !this.GetType().Equals(obj.GetType()))
				{
					return false;
				}
				else
				{
					Jumper p = (Jumper)obj;
					return (secondName == p.secondName) && (poll == p.poll) && (countOfMedales == p.countOfMedales);
				}
			}
			public override string ToString()
			{
				return " Second name: " + secondName + "\n Poll: " + poll + "\n Count of medales = " + countOfMedales.ToString() + "\n";
			}
		}
		class Runer
		{
			string secondName;
			string poll;
			int countOfMedales;
			public Runer(string s, string p, int c)
			{
				this.secondName = s;
				this.poll = p;
				this.countOfMedales = c;
			}
			private Runer(string s)
			{
				this.secondName = s;
			}
			public override bool Equals(Object obj)
			{
				if ((obj == null) || !this.GetType().Equals(obj.GetType()))
				{
					return false;
				}
				else
				{
					Runer p = (Runer)obj;
					return (secondName == p.secondName) && (poll == p.poll) && (countOfMedales == p.countOfMedales);

				}
			}
			public override string ToString()
			{
				return " Second name: " + secondName + "\n Poll: " + poll + "\n Count of medales = " + countOfMedales.ToString() + "\n";
			}
			protected void ShowMedals(Runer p)
			{
				Console.WriteLine(p.countOfMedales);
			}
		}
		static void Main(string[] args)
		{

			// Одномірний масив без ініціалізації
			int[] mass1a = new int[5];
			// Одномірний масив з ініціалізацією
			int[] mass1b = { 5, 3, 9, 8, 6, 1 };
			int sum1 = 0;
			Console.WriteLine(" Massiv`s length = " + mass1b.Length);
			Console.Write(" Our massiv number 1: ");
			for (int i = 0; i < mass1b.Length; i++)
			{
				Console.Write($"{mass1b[i]} ");
				sum1 += mass1b[i];
			}
			Console.WriteLine("\n Summa massiv`s elements = " + sum1);

			// Двомірний-квадратний масив без ініціалізації
			int[, ] mass2a = new int[5, 6];
			// Двомірний-квадратний масив з ініціалізацією
			int[, ] mass2b = { { 5, 6, 8 }, { 3, 8, 9 } };
			int sum2 = 0;
			int rows = mass2b.GetUpperBound(0) + 1;  // Отримуємо індекс останнього елемента першого рядка данного рядка
			int columns = mass2b.Length / rows;  // Вираховуємо кількість стовбців
			Console.WriteLine(" Our massiv number 2: ");
			//foreach(int num in mass2b)
			//{
			//    Console.Write($" {num}");
			//    sum2 += num;
			//}
			Console.WriteLine(" Number of rows = " + rows);
			Console.WriteLine(" Number of columns = " + columns

			);
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					Console.Write($" {mass2b[i, j]}\t");
					sum2 += mass2b[i, j];
				}
				Console.WriteLine();
			}
			Console.WriteLine("\n Summa massiv`s elements = " + sum2 + "\n");

			// Двомірний-невирівняний масив без ініціалізації
			int[][] mass3a = new int[3][];
			mass3a[0] = new int[5];
			mass3a[1] = new int[4];
			mass3a[2] = new int[3];
			// Двомірний-невирівняний масив з ініціалізацією
			int[][] mass3b = new int[3][];
			mass3b[0] = new int[2]{ 2, 6 };
			mass3b[1] = new int[3]{ 5, 7, 1 };
			mass3b[2] = new int[2]{ 3, 9 };
			int rowsMass3 = mass3b.Length;
			Console.WriteLine(" Number of rows = " + rowsMass3);
			for (int i = 0; i < rowsMass3; i++)
			{
				Console.WriteLine($" Number of colums in {i + 1} row = " + mass3b[i].Length);
			}
			int sum3 = 0;
			Console.WriteLine(" Our massiv number 3: ");
			foreach(int[] num1 in mass3b)
			{
				foreach(int value in num1)
				{
					Console.Write($" {value}");
					sum3 += value;
				}
			}
			Console.WriteLine("\n Summa massiv`s elements = " + sum3 + "\n");

			// TASK 3
			// Пошук елементу
			Console.Write(" Enter a number to search: ");
			int numberToSearch = int.Parse(Console.ReadLine());
			int count1 = 0, count2 = 0, count3 = 0;
			foreach(int i1 in mass1b)
			{
				if (i1 == numberToSearch)
				{
					count1++;
				}
			}
			Console.WriteLine(" In first massiv your number was fond = " + count1 + " times;");
			foreach(int i2 in mass2b)
			{
				if (i2 == numberToSearch)
				{
					count2++;
				}
			}
			Console.WriteLine(" In second massiv your number was fond = " + count2 + " times;");
			foreach(int[]i31 in mass3b)
			{
				foreach(int i32 in i31)
					if (i32 == numberToSearch)
					{
						count3++;
					}
			}
			Console.WriteLine(" In third massiv your number was fond = " + count3 + " times;\n");

			// TASK 4
			Runer r1 = new Runer("Greg", "M", 12);
			Runer r2 = new Runer("Alex", "M", 10);

			if (r1.Equals(r2))
			{
				Console.WriteLine(" Yes ");
			}
			else
			{
				Console.WriteLine(" No ");
			}
			// TASK 5
			Runer r3 = new Runer("Mike", "M", 15);
			Console.WriteLine(r3.ToString());

			// TASK 7 
			Jumper j1 = new Jumper("Danny", "M", 9);
			Jumper j2 = new Jumper("Anna", "W", 15);
			if (j1.Equals(j2))
			{

				Console.WriteLine(" Yes ");
			}
			else
			{
				Console.WriteLine(" No ");
			}
			Console.WriteLine(j1.ToString());
			Console.WriteLine(j2.ToString());

			Console.ReadKey();
		}
	}
}
\