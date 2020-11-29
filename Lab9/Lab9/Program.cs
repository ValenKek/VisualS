using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    internal class MyExeption : Exception
    {
        public MyExeption() : base()
        {
        }
        public MyExeption(string message) : base(message)
        {
        }

        public MyExeption(string message, Exception innerException) : base(message, innerException)
        {
        }

        public override string Message => base.Message;
    }
    internal class Program
    {
        private static void Main(string[] args)
        {
            ExerciseOne();
            ExerciseTwo();
            ExerciseThree();
            ExerciseFour();
            ExerciseFive();
            Console.ReadKey();
        }
        static public void IsDigit(string str)
        {
            for (int i = 0, length = str.Length; i < length; ++i)
            {
                if (!Char.IsDigit(str[i]))
                {
                    throw new MyExeption();
                }
            }
        }

        private static void ExerciseOne()
        {
            try
            {
                int[] arr = { 1, 2, 3, 4 };
                Console.WriteLine(arr[4]);
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine(ex.StackTrace);
            }
        }



        private static void ExerciseTwo()
        {
            try
            {
                int a = 1, b = 0;
                Console.WriteLine(a / b);
            }
            catch
            {
                Console.WriteLine("Erroe /0");
            }
        }

        private static void ExerciseThree()
        {
            try
            {
                DivideByZeroExeptionEmulator();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Message\n" + ex.Message + "\nStack\n" + ex.StackTrace);
            }
        }

        private static void ExerciseFour()
        {
            try
            {
                Console.WriteLine("Error Exercise Four");
            }
            finally
            {
                Console.WriteLine("Error Exercise Four+finally");
            }

            try
            {
                throw new Exception("143");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error {ex.GetType()} - '{ex.Message}'");
            }
            finally
            {
                Console.WriteLine("Error Exercise Four+finally2");
            }
        }

        private static void ExerciseFive()
        {
            try
            {
                IsDigit("example");
            }
            catch (MyExeption ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.WriteLine("Error");
            }
        }

        private static void SixthExercise()
        {
            try
            {
                string str = null;
                Console.WriteLine(str.Contains(":)"));

                IsDigit(str);

                Nullable<Int32>[] integers = { null, 345, 43 };
                var selected = integers.Select(integer => (int)integer);
                foreach (var integer in selected)
                {
                    Console.WriteLine(integers);
                }
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine("ghgfh");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        private static void DivideByZeroExeptionEmulator()
        {
            try
            {
                int i = 1, b = 0; ;
                Console.WriteLine(i / b);
            }
            catch (DivideByZeroException ex)
            {
                Console.WriteLine(ex.Message + "error in -> " + ex.StackTrace);
                throw new DivideByZeroException("Divide By Zero error", ex);
            }
        }
    }  
}
