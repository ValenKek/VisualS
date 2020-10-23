using System;

namespace Lab7
{
    internal enum Month : int
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    }

    internal class Device<T>
    {
        private T price = default(T);
        private T prodCost = default(T);
        public static T x;

        public Device(T price, T prodCost)
        {
            this.price = price; this.prodCost = prodCost;
        }

        public override string ToString()
        {
            return "price=" + price + " prodaction cost=" + prodCost + " x=" + x;
        }

        public void Swap<T>(ref T x, ref T y)
        {
            T temp = x;
            x = y;
            y = temp;
        }
    }

    internal class Device2<T1, T2>
    {
        private T1 price = default(T1);
        private T1 prodCost = default(T1);
        public static T2 x;

        public Device2(T1 price, T1 prodCost)
        {
            this.price = price; this.prodCost = prodCost;
        }

        public override string ToString()
        {
            return "price=" + price + " prodaction cost=" + prodCost + " x=" + x;
        }
    }

    public static class IntExtensions
    {
        public static bool IsGreaterThan(this int x, int value)
        {
            return x > value;
        }
    }

    internal class Program
    {
        private static void Main(string[] args)
        {
            var val = Enum.GetValues(typeof(Month));
            foreach (var item in val)
            {
                Show(item);
            }

            Console.WriteLine("\n");
            Device<int> dev1 = new Device<int>(5, 9);
            Device<int>.x = 3;
            Device<double> dev2;
            dev2 = new Device<double>(1.5, 6.3);
            Device<double>.x = 3.3;
            Console.WriteLine(dev1 + "\n");
            Console.WriteLine(dev2 + "\n");

            Device2<int, string> dev3 = new Device2<int, string>(1, 2);
            Device2<int, string>.x = "test";
            Console.WriteLine(dev3 + "\n");
            int x = 65, y = 56;
            dev1.Swap<int>(ref x, ref y);
            Console.WriteLine(x + " " + y + "\n");

            Console.WriteLine(x.IsGreaterThan(y));
            
        }

        private static void Show(Object val)
        {
            Console.WriteLine((int)val + " " + val);
        }
    }
}