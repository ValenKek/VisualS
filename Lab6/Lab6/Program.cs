using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp16
{

    sealed class Device
    {
        public string name { private set; get; }
        public string serialNumber { private set; get; }
        public int price { private set; get; }

        public Device()
        {
            name = null;
            serialNumber = null;
        }
        public Device(string name, int price, string serialNumber = null)
        {
            this.name = name;
            this.price = price;
            this.serialNumber = serialNumber;
        }
        public static int operator +(Device firstDevice, Device secondDevice)
        {
            return firstDevice.price + secondDevice.price;
        }
        public static Device operator -(Device Device, int price)
        {
            Device.price -= price;
            return Device;
        }
        public static Device operator ++(Device Device)
        {
            return new Device(Device.name, Device.price += 100, Device.serialNumber);
        }
        public static explicit operator Device(int num)
        {
            return new Device(null, num);
        }

        public static implicit operator int(Device Device)
        {
            return Device.price;
        }
        public override string ToString()
        {
            return "Name "+name+"\nPrice "+ price+"\nSerial number "+serialNumber;
        }
    }
    static class DeviceControll
    {
        public static int SameDevices(this Device[] Devices, string name)
        {
            return (
                    from Device in Devices
                    where string.Equals(Device.name, name)
                    select Device
                    ).Count();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Device[] Devices = { new Device(), new Device() };

            Console.WriteLine(Devices.SameDevices("hh"));

            int price = Devices[0] + Devices[1];
            Device Device = Devices[0] - Devices[1];
            Device++;
            Console.WriteLine(((Device)32).ToString());
        }
    }
}