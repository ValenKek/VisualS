using System;

namespace ConsoleApp7
{
    internal class Program
    {
        static public void Method(String str)
        {
            str = "lll";//создастся новая строка, оригинал не изменится
        }

        private class Point
        {
            private int x;
            private int y;

            public Point(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
            public virtual void Show()
            {
                Console.WriteLine("I am a point");
            }
            public override string ToString()
            {
                return " X="+x+" Y="+y;
            }
        }

        private class Line : Point
        {
            private string name;

            public Line(string name, int x, int y) : base(x, y)
            {
                this.name = name;
            }
            public override void Show()
            {
                base.Show();
                Console.WriteLine("I am a line");
            }
            public override string ToString()
            {
                return "Name:"+name+base.ToString();
            }
        }

        private static void Main(string[] args)
        {
            string str = "abc";
            Method(str);
            Console.WriteLine(str);
            Point pl = new Line("AB", 2, 3);
            pl.Show();
            Console.WriteLine(pl.ToString());
        }
    }
}