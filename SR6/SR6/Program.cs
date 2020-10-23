using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace SR6
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
        public static int operator+(int x,Point point)
        {
            return x + point.y;
        } 
    }
    class Alien
    {
        public const string race = "AlianRace";
        public readonly string sex;
        public string Name { set; get; }
        public int Age { set; get; }
        public Alien(string sex, string Name, int Age) {
            this.sex = sex;
            this.Name = Name; 
            this.Age = Age; 
        }
        public static Alien operator +(Alien a1, Alien a2)
        {
            return new Alien(a1.sex,a1.Name, (a1.Age+a2.Age)/2) ;
        }
        public override string ToString()
        {
            return "\nRace:" + race + "\nSex: " + sex + "\nName: "+Name+"\nAge: "+Age;
        }
    }
    class Earthlings
    {
        public readonly string sex;
        public string Name { set; get; }
        public int Age { set; get; }
        public Earthlings(string sex, string Name, int Age)
        {
            this.sex = sex;
            this.Name = Name;
            this.Age = Age;
        }
        public static Alien operator +(Alien a1,Earthlings e1)
        {
            return new Alien(a1.sex, a1.Name, e1.Age);
        }
        public override string ToString()
        {
            return "\nSex: " + sex + "\nName: " + Name + "\nAge: " + Age;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Point p1=new Point(5,10);
            int i = 5 + p1;
            Console.WriteLine(i);
            Alien a1 = new Alien("Alien1Sex", "Alien1Name", 35);
            Alien a2 = new Alien("Alien2Sex", "Alien2Name", 19);
            Console.WriteLine(a1 + a2);
            Earthlings e1 =new Earthlings("Earthlings2Sex", "Earthlings2Name", 30);
            Console.WriteLine(a1+e1);
        }
    }
}
