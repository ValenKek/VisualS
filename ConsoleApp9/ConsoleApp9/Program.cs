using System;

namespace ConsoleApp9
{
    internal class Point
    {
        private int x;
        private int y;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public string show()
        {
            return " x = " + x + " y = " + y;
        }

        public override string show()
        {
            return " x = " + x + " y = " + y;
        }
    }

    internal class Program
    {
        public override int Equals(int x, int y);
        {
            if (x > y)
            {
            return x;
            }
            return y;
        }
}