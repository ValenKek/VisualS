using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            //1
            int[] arr1 = { 1, 4, 4, 5 };
            int[] arr2;
            int multi = 1;
            foreach (var item in arr1)
            {
                multi *= item;
            }
            //2
            int[,] arr3 = { { 1, 2, 3 }, { 3, 4, 2 }, { 4, 2, 1 } };
            int[,] arr4;
            int[][] arr5 = { new int[] { 1, 2, 3, 4 }, new int[] { 2, 1, 2 }, new int[] { 2, 2 } };
            int[][] arr6;
            int multi2 = 1;
            foreach (var item in arr3)
            {
                multi2 *= item;
            }
            int multi3 = 1;
            foreach (var item1 in arr5)
            {
                foreach (var item2 in item1)
                {
                    multi3 *= item2;
                }
            }
            //3
            string input;
            input = Console.ReadLine();
            int number;
            Int32.TryParse(input, out number);
            int repeat = 0;
            //Пошук кiлькостi елементiв за заданим значенням
            foreach (var item in arr1)
            {
                if (item == number) repeat++;
            }
            foreach (var item in arr3)
            {
                if (item == number) repeat++;
            }
            foreach (var item1 in arr5)
            {
                foreach (var item2 in item1)
                {
                    if (item2 == number) repeat++;
                }
            }
            Console.WriteLine(repeat);
            //7
            Example ex1 = new Example();
            Example ex2 = new Example(5);
            Example ex3 = new Example(5);
            Console.WriteLine(ex2.Equals(ex3)); // true потому что значение полей одинаковые
            Console.WriteLine(ex1.ToString());
            Console.Read();
        }
        //4 5 6
        internal class Country
        {
            public int X { get; set; }
            public override bool Equals(object obj)
            {
                if ((obj == null) || !(this.GetType().Equals(obj.GetType())))
                {
                    return false;
                }
                else
                {
                    Country ob = (Country)obj;
                    return (X == ob.X);
                }
            }
            public override string ToString()
            {
                return $"x = {this.X}";
            }
        }
        struct Example
        {
            int x;
            public Example(int x)
            {
                this.x = x;
            }
            public override string ToString()
            {
                return $"x = {x}";
            }
        }


    }
}


