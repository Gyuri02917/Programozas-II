using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(VanTelefonszam("Kapcsolat: +36 30 123 4567") ? "A bemenet tartalmaz elérhetőséget!" : "A bemenet NEM tartalmaz elérhetőséget!");
            Console.WriteLine(VanTelefonszam("Ötvös Csöpi, Balatonfüred") ? "A bemenet tartalmaz elérhetőséget!" : "A bemenet NEM tartalmaz elérhetőséget!");
            Console.WriteLine(VanTelefonszam("Telefon: 06 20 987 6543") ? "A bemenet tartalmaz elérhetőséget!" : "A bemenet NEM tartalmaz elérhetőséget!");
            Console.WriteLine(VanTelefonszam("Csak email: info@nje.hu") ? "A bemenet tartalmaz elérhetőséget!" : "A bemenet NEM tartalmaz elérhetőséget!");
        }

        static bool VanTelefonszam(string bemenet)
        {
            // +36 vagy 06 formátumú telefonszám keresése
            return bemenet.Contains("+36") || bemenet.Contains("06 ");
        }
    }
}
