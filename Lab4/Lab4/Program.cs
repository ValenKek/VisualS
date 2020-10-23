using System;

namespace Lab4
{
    internal class Program
    {
        //    #1
        public static void ValueFunc(int x)
        {
        }

        public static void RefFunc(ref int x)
        {
            x = 10;
        }

        public static void OutFunc(out int x)
        {
            x = 5;
        }

        public static void OutC7Func(out int x)
        {
            x = 7;
        }

        public static void ParamsFunc(params int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine();
        }

        public static int NamedFunc(int a, int b)
        {
            return (a * b);
        }

        public static void NotImportFunc(int x, int y = 5)
        {
        }

        public static void TwoOrMore(int x, int y, params int[] other)
        {
        }

        //    #2
        private class MyClass
        {
            public static int staticX = 50;
            public const int constX = 1;
            public readonly int readonlyX;

            static MyClass()
            {
                staticX = 99;
            }

            MyClass(int x)
            {
                readonlyX = x;
            }
        }

        //    #3.a
        public class ArrIndex
        {
            public int[] oneDArra;
            public int[,] twoDArra;

            public int this[int index, bool isOneD = true, int index2 = 0]
            {
                get
                {
                    if (isOneD)
                    {
                        return (oneDArra[index]);
                    }
                    return (twoDArra[index, index2]);
                }

                set
                {
                    if (isOneD)
                    {
                        oneDArra[index] = value;
                        return;
                    }
                    twoDArra[index, index2] = value;
                }
            }
        }

        public static void Main(string[] args)
        {
            //    #1
            int x, z = 1;
            RefFunc(ref z);
            OutFunc(out x);
            OutC7Func(out int y);
            y = 54;
            NamedFunc(a: y, b: x);
            NotImportFunc(x);
            //    #3
            int[] arr = { 1, 2, 3, 4, 5 };
            Array.Clear(arr, 2, 2);
            foreach (int item in arr)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\n");
            Array.Reverse(arr);
            foreach (int item in arr)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("\n");
            Array.Resize(ref arr, 4);
            foreach (int item in arr)
            {
                Console.WriteLine(item);
            }
        }
    }
}