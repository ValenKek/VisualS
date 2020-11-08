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
        public interface Device
        {
            void Show();
        }
        class TV : Device
        {
            public Int32 Voltage { get; private set; }
            public String ModelName { get; private set; }
            public String ProductionQuantity { get; private set; }

            public void Show()
            {
                Console.WriteLine($"Company -> {ModelName}\nNum of pages -> {Voltage}");
            }
        }
        class Phone : Device, IComparable<Phone>
        {
            public Phone(Int32 voltage, String company, Int32 productionQuantity)
            {
                Voltage = voltage;
                Company = company;
                ProductionQuantity = productionQuantity;
            }
            public Int32 Voltage { get; private set; }
            public String Company { get; private set; }
            public Int32 ProductionQuantity { get; private set; }

            public Int32 CompareTo(Phone other)
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
                Int32 IComparer.Compare(object x, object y)
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
                Int32 IComparer.Compare(object x, object y)
                {
                    Phone b1 = (Phone)x;
                    Phone b2 = (Phone)y;

                    return String.Compare(b1.Company, b2.Company);
                }
            }
            private class SortByProductionQuantityHelper : IComparer
            {
                Int32 IComparer.Compare(object x, object y)
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
        class Depot : IEnumerable
        {
            private Train[] _trains;
            public Depot(Train[] trains)
            {
                Int32 length = trains.Length;
                _trains = new Train[length];
                for (int index = 0; index < length; ++index)
                {
                    _trains[index] = trains[index];
                }
            }
            IEnumerator IEnumerable.GetEnumerator()
            {
                return (IEnumerator)GetEnumerator();
            }
            public DepotEnum GetEnumerator()
            {
                return new DepotEnum(_trains);
            }
        }
        public class DepotEnum : IEnumerator
        {
            public Train[] _trains;

            // Enumerators are positioned before the first element
            // until the first MoveNext() call.
            int position = -1;

            public DepotEnum(Train[] list)
            {
                _trains = list;
            }

            public bool MoveNext()
            {
                position++;
                return (position < _trains.Length);
            }

            public void Reset()
            {
                position = -1;
            }

            object IEnumerator.Current
            {
                get
                {
                    return Current;
                }
            }

            public Train Current
            {
                get
                {
                    try
                    {
                        return _trains[position];
                    }
                    catch (IndexOutOfRangeException)
                    {
                        throw new InvalidOperationException();
                    }
                }
            }
        }
        public class Train
        {
            public String Type { get; private set; }
            public Int32 Volume { get; private set; }
            public Int32 Year { get; private set; }

            public Train(String type, Int32 volume, Int32 year)
            {
                Type = type;
                Volume = volume;
                Year = year;
            }


        }
        static void Main(String[] args)
        {
            Phone[] Phones = { new Phone(2, "b", 3), new Phone(4, "z", 1), new Phone(1, "a", 1) };
            Array.Sort(Phones, Phone.SortByCompany());
            Console.WriteLine("Sort by Company name");
            foreach (var item in Phones)
            {
                Console.WriteLine(item.Company);
            }
            Train[] trains = { new Train("first", 1, 1), new Train("second", 2, 2) };
            Depot depot = new Depot(trains);
            depot.GetEnumerator().MoveNext();

            foreach (var item in depot)
            {
                Console.WriteLine(item.GetType());
            }
            Console.ReadKey();
        }

        public static void Method(Device printedEdition)
        {
            printedEdition.Show();
        }
    }

}