using System;
using System.Collections.Generic;

namespace Lab5
{
    internal abstract class RestPlaces
    {
        public string type;
        public int placeQuant;
        public int workHour;

        public RestPlaces(string type, int placeQuant, int workHour)
        {
            this.type = type;
            this.placeQuant = placeQuant;
            this.workHour = workHour;
        }
        public override string ToString()
        {
            return " Type= " + type + " Place Quantity= " + placeQuant + " Work Hours= " + workHour;
        }

        public double Func()
        {
            return (placeQuant*1.0) / workHour;
        }
    }

    internal sealed class Bar : RestPlaces
    {
        public string name;

        public Bar(string type, int placeQuant, int workHour, string name) : base(type, placeQuant, workHour)
        {
            this.name = name;
        }

        public override string ToString()
        {
            return base.ToString() + " Name= " + name;
        }
    }

    //internal class MySealedClassExample:Bar{} - помилка, не може наслідувати sealed class

    public partial class MyPartClass
    {
        public void FirstFunc()
        {
            Console.WriteLine("First part");
        }
    }

    public partial class MyPartClass
    {
        public void SecondFunc()
        {
            Console.WriteLine("Second part");
        }
    }

    public class Program
    {
        private static void Method1(object obj)
        {
            if (obj.Equals(null)) return;

            Bar br = obj as Bar;
            if (br.Equals(null))
            {
                Console.WriteLine("Cast error");
                return;
            }
            Console.WriteLine(br.ToString());
        }

        private static void Method2(RestPlaces obj)
        {
            if (obj.Equals(null)) return;

            Console.WriteLine(obj.Func());
        }



        private static void Main(string[] args)
        {

            Bar b1 = new Bar("BarType", 30, 8, "BarName");
            Console.WriteLine(b1);

            MyPartClass mpc = new MyPartClass();
            mpc.FirstFunc();
            mpc.SecondFunc();

            char[] chr = { 'B', 'a', 's', 'e', 'd', '\0' };
            string str11;
            str11 = new string(chr);
            Console.WriteLine(str11);

            string str12;
            str12 = new string('a', 6);
            Console.WriteLine(str12);

            string str1 = "world";
            string str2 = str1.Insert(0, "Hallo ");
            Console.WriteLine(str2);

            string str3 = str2.Remove(5, 2);
            Console.WriteLine(str3);

            str3 = str3.Replace("l", "b");
            Console.WriteLine(str3);

            string str4 = String.Copy(str3);

            string str5 = "Hallo";
            Console.WriteLine("Str5=" + str5 + "\nEnter string to demontrate IsInterned:");
            str5 = Console.ReadLine();
            Console.WriteLine(String.IsInterned(str5));
            String.Intern(str5);
            Console.WriteLine(String.IsInterned(str5));

            string str6 = "Bababooey";
            string str7 = "Bababooey";

            Console.WriteLine(String.Equals(str6, str7));//Определяет, совпадают ли значения двух указанных объектов System.String.
            Console.WriteLine(Object.Equals(str6, str7));//Определяет, считаются ли равными указанные экземпляры объектов.
            if (str6 == str7) Console.WriteLine("true");
            else Console.WriteLine("false");

            const string cstr ="Based";

            Method1(new Bar("BarType", 30, 8, "BarName"));

            List<RestPlaces> rp=new List<RestPlaces>();
            rp.Add(new Bar("BarType", 30, 8, "BarName"));
            rp.Add(new Bar("BarType2", 20, 7, "BarName2"));
            foreach(RestPlaces item in rp)
            {
                Console.WriteLine(item.ToString()) ;
            }
        }
    }
}