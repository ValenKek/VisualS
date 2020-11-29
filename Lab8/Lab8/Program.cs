using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8
{

    class Program
    {

        public static void Method(IDevice device)
        {
            device.Show();
        }

        public interface IDevice
        {
            void Show();
            int Voltage { get; set; }
            string ModelName { get; set; }
            int ProductionQuantity { get; set; }
        }
        class TV : IDevice
        {
            public int Voltage { get; set; }
            public string ModelName { get; set; }
            public int ProductionQuantity { get; set; }
            public void Show()
            {
                Console.WriteLine($"Company -> {ModelName}\nNum of pages -> {Voltage}");
            }
        }
        class Phone : IDevice, IComparable<Phone>
        {
            public Phone(int voltage, string company, int productionQuantity)
            {
                Voltage = voltage;
                Company = company;
                ProductionQuantity = productionQuantity;

            }

            public string ModelName { get; set; }
            public int Voltage { get; set; }
            public string Company { get; set; }
            public int ProductionQuantity { get; set; }


            public int CompareTo(Phone other)
            {
                throw new NotImplementedException();
            }

            public void Show()
            {
                Console.WriteLine($"Company -> {Company}\nVoltage -> {Voltage}");
            }
            public static IComparer SortByCompany()
            {
                return (IComparer)new SortByCompanyHelper();
            }
            public static IComparer SortByVoltage()
            {
                return (IComparer)new SortByVoltageHelper();
            }
            public static IComparer SortByProductionQuantity()
            {
                return (IComparer)new SortByProductionQuantityHelper();
            }

            private class SortByVoltageHelper : IComparer
            {
                int IComparer.Compare(object x, object y)
                {
                    Phone b1 = (Phone)x;
                    Phone b2 = (Phone)y;

                    if (b1.Voltage > b2.Voltage)
                        return 1;
                    if (b2.Voltage < b2.Voltage)
                        return -1;
                    return 0;
                }
            }
            private class SortByCompanyHelper : IComparer
            {
                int IComparer.Compare(object x, object y)
                {
                    Phone b1 = (Phone)x;
                    Phone b2 = (Phone)y;

                    return string.Compare(b1.Company, b2.Company);
                }
            }
            private class SortByProductionQuantityHelper : IComparer
            {
                int IComparer.Compare(object x, object y)
                {
                    Phone b1 = (Phone)x;
                    Phone b2 = (Phone)y;

                    if (b1.ProductionQuantity > b2.ProductionQuantity)
                        return 1;
                    if (b2.ProductionQuantity < b2.ProductionQuantity)
                        return -1;
                    return 0;
                }
            }
        }

        public class PartOfTheWorld
        {
            public string PartOfTheWorldName { get; set; }
            public Country[] CountryItThePartOfTheWorld;
            public PartOfTheWorld(string name, Country[] CountryItThePartOfTheWorld)
            {
                PartOfTheWorldName = name;
                this.CountryItThePartOfTheWorld = CountryItThePartOfTheWorld;
            }
            public void Show()
            {
                foreach (Country item in CountryItThePartOfTheWorld)
                {
                    item.Show();
                }
            }
        }
        public class Country
        {
            public string Name { get;  set; }
            public int Population { get;  set; }
            public int Area { get;  set; }

            public Country(string name, int population, int area)
            {
                Name = name;
                Population = population;
                Area = area;
            }
            public void Show()
            {
                Console.WriteLine(Name +" " +Population + " "+ Area+"\n");
            }

        }
        static void Main(string[] args)
        {
            Phone[] Phones = { new Phone(2, "ads", 3), new Phone(4, "dsa", 1), new Phone(1, "bvc", 1) };

            Array.Sort(Phones, Phone.SortByCompany());

            Console.WriteLine("Sort by Company name");
            foreach (var item in Phones)
            {
                Console.WriteLine(item.Company);
            }

            Country[] countrys = { new Country("CountryName1", 123456, 7891), new Country("CountryName2", 123456321, 432456) };

            PartOfTheWorld potw=new PartOfTheWorld ( "Africa", countrys);
            potw.Show();

        }
    }
}