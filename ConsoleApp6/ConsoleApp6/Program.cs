using System;

namespace ConsoleApp6
{
    public class Alien
    {
        private const string race = "RaceName";
        private readonly string sex;

        public string Name { set; get; }

        public Alien(string sex, string name)
        {
            this.sex = sex;
            this.Name = name;
        }
        public override string ToString()
        {
            return race + " " + Name + " " + sex;
        }
    }
    internal class Program
    {
        private static int Random1(out int n)
        {
            Random r = new Random();
            n = r.Next();
            return n;
        }
        private static int Random2(ref int n)
        {
            Random r = new Random();
            n = r.Next();
            return n;
        }

        private static void glovo(params int[] time)
        {
            int sum = 0;
            foreach (int item in time)
            {
                sum += item;
            }
            Console.WriteLine(sum + " " + time.Length);
        }

        private static void Main(string[] args)
        {
            glovo(10, 5, 6, 7);
            int n = 0;
            Random1(out var m);
            Random2(ref n);
            Alien al1 = new Alien("male","Ivan");
            Console.WriteLine(al1.ToString());
        }
    }
}