using System;

namespace ZH
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Adja meg a fájl elérését:");
            string fajlnev = Console.ReadLine();

            Flotta f = new Flotta();
            f.Beolvas(fajlnev);

            while (true)
            {
                Console.WriteLine("\nVálasszon:");
                Console.WriteLine("1 - Hajók listázása");
                Console.WriteLine("2 - Átlagár adott időre");
                Console.WriteLine("3 - Legdrágább hajó");
                Console.WriteLine("4 - Legolcsóbb hajó");
                Console.WriteLine("5 - Szűrés típusra");
                Console.WriteLine("6 - Szűrés árra");
                Console.WriteLine("0 - Kilépés");

                int val = int.Parse(Console.ReadLine());

                switch (val)
                {
                    case 0: return;

                    case 1:
                        f.Mutat();
                        break;

                    case 2:
                        Console.Write("Óraszám: ");
                        int o1 = int.Parse(Console.ReadLine());
                        Console.WriteLine("Átlagár: " + f.AtlagAr(o1));
                        break;

                    case 3:
                        Console.Write("Óraszám: ");
                        int o2 = int.Parse(Console.ReadLine());
                        var d = f.Legdragabb(o2);
                        Console.WriteLine($"Legdrágább: {d.Nev}, {d.BerletiDij(o2)} Ft");
                        break;

                    case 4:
                        Console.Write("Óraszám: ");
                        int o3 = int.Parse(Console.ReadLine());
                        var ol = f.Legolcsobb(o3);
                        Console.WriteLine($"Legolcsóbb: {ol.Nev}, {ol.BerletiDij(o3)} Ft");
                        break;

                    case 5:
                        Console.Write("Típus: ");
                        string t = Console.ReadLine();
                        f.SzuresTipusra(t);
                        break;

                    case 6:
                        Console.Write("Max ár: ");
                        int max = int.Parse(Console.ReadLine());
                        Console.Write("Óraszám: ");
                        int o4 = int.Parse(Console.ReadLine());
                        f.SzuresArra(max, o4);
                        break;
                }
            }
        }
    }
}
