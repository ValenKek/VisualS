using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp8
{
    class Program
    {
        class Point
        {
            int x;
            int y;
            public Point(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
            static public Point operator +(Point p1, Point p2)
            {
                return new Point(p1.x + p2.x, p1.y + p2.y);
            }
            public static implicit operator Point(int number)
            {
                return new Point(number, number);
            }
        }

        static void Main(string[] args)
        {
            Point p = (new Point(1,2))+ 5;
        }
    }
}
