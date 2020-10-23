using System;

namespace ConsoleApp3
{
    //#4 #5 #6
    public class RestPlaces
    {
        public int places { get; set; }
        string name;
        string location;

        public override bool Equals(object obj)
        {
            if ((obj == null) || !(this.GetType().Equals(obj.GetType())))
            {
                return false;
            }
            else
            {
                RestPlaces ob = (RestPlaces)obj;
                return (places == ob.places && name == ob.name && location == ob.location);
            }
        }
    }

    struct Example
    {
        int x;
        int y;
        public Example(int x)
        {
            y = x;
            this.x = x;
        }

        public override string ToString()
        {
            return $"x = {x}";
        }
    }

    public class Program
    {
        private static void Main(string[] args)
        {
            //#1
            //One-dimensional array
            int sum = 0;
            int[] arr1 = { 1, 2, 3, 4, 5 };
            int[] arr11;
            foreach (var item in arr1)
            {
                sum += item;
            }
            Console.WriteLine($"Sum={sum}\n");

            //#2
            //Two-dimensional rectangular array
            sum = 0;
            int[,] arr2 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            int[,] arr21;
            foreach (var item in arr2)
            {
                sum += item;
            }
            Console.WriteLine($"Sum={sum}\n");
            //Two-dimensional jagged array
            sum = 0;
            int[][] arr3 = { new int[] { 1 }, new int[] { 2, 3 }, new int[] { 4, 5 } };
            int[][] arr31;
            foreach (var item1 in arr3)
            {
                foreach (var item2 in item1)
                {
                    sum += item2;
                }
            }

            Console.WriteLine($"Sum={sum}\n");

            int mul2 = 1;
            for (int i = 0; i < arr1.Length; i += 2)
            {
                mul2 *= arr1[i];
            }
            mul2 = 1;
            for (int i = 0; i < arr3.Length; i += 2)
            {
                for (int j = 0; j < arr3[i].GetLength(0); j++)
                {
                    mul2 *= arr3[i][j];
                }
            }

            //#3
            int count1 = 0, count2 = 0, count3 = 0;
            Console.Write("Number to search: ");
            int number = int.Parse(Console.ReadLine());
            foreach (int item1 in arr1)
            {
                if (item1 == number)
                {
                    count1++;
                }
            }
            Console.WriteLine(" In first arr: " + count1 + " times;");
            foreach (int item2 in arr2)
            {
                if (item2 == number)
                {
                    count2++;
                }
            }
            Console.WriteLine(" In second arr:  " + count2 + " times;");
            foreach (int[] item31 in arr3)
            {
                foreach (int item32 in item31)
                    if (item32 == number)
                    {
                        count3++;
                    }
            }
            Console.WriteLine(" In third arr:  " + count3 + " times;\n");

            //#7
            Example ex1 = new Example();
            Example ex2 = new Example(5);
            Example ex3 = new Example(5);
            Console.WriteLine(ex2.Equals(ex3));
            Console.WriteLine(ex1.ToString());
            Console.Read();
        }
    }
}