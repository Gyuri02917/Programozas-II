using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    enum Tipus { Katamaran, Szemely, Komp, Egyeb }

    struct Meretek
    {
        public double? LegnagyobbHossz;
        public double? HosszFuggely;
        public double? LegnagyobbSzelesseg;
        public double? SzelessegFoborda;
        public double? FixpontMagassag;
        public double? Oldalmagassag;
        public double? LegnagyobbMerules;

        public Meretek(double? lh, double? hf, double? ls, double? sf, double? fm, double? om, double? lm)
        {
            LegnagyobbHossz = lh;
            HosszFuggely = hf;
            LegnagyobbSzelesseg = ls;
            SzelessegFoborda = sf;
            FixpontMagassag = fm;
            Oldalmagassag = om;
            LegnagyobbMerules = lm;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Flotta f = new Flotta();

            Console.Write("Fájl neve: ");
            string file = Console.ReadLine();

            f.Beolvas(file);

            while (true)
            {
                Console.WriteLine("\n--- MENÜ ---");
                Console.WriteLine("1 – Rövid listázás (Info)");
                Console.WriteLine("2 – Részletes listázás (ToString)");
                Console.WriteLine("3 – Új hajó felvétele");
                Console.WriteLine("4 – Mentés");
                Console.WriteLine("5 – Kilépés");

                Console.Write("Választás: ");
                string v = Console.ReadLine();

                // 1) Rövid listázás
                if (v == "1")
                {
                    foreach (var j in f.Jarmuvek)
                        j.Info();
                }

                // 2) Részletes listázás (ToString override)
                else if (v == "2")
                {
                    foreach (var j in f.Jarmuvek)
                    {
                        Console.WriteLine("\n-------------------------");
                        Console.WriteLine(j.ToString());
                    }
                }

                // 3) Új hajó felvétele
                else if (v == "3")
                {
                    Console.WriteLine("\nÚj hajó felvétele:");

                    Console.Write("ENI: ");
                    int eni = int.Parse(Console.ReadLine());

                    Console.Write("Név: ");
                    string nev = Console.ReadLine();

                    Console.WriteLine("Típus (0=Katamaran, 1=Szemely, 2=Komp, 3=Egyeb): ");
                    Tipus tipus = (Tipus)int.Parse(Console.ReadLine());

                    // példányosítás típustól függően
                    Jarmu uj = tipus switch
                    {
                        Tipus.Katamaran => new Katamaran(eni, nev),
                        Tipus.Szemely => new Szemely(eni, nev),
                        Tipus.Komp => new Komp(eni, nev),
                        _ => new Egyeb(eni, nev)
                    };

                    f.UjHajoFelvetele(uj);
                    Console.WriteLine("Hajó sikeresen hozzáadva!");
                }

                // 4) Mentés
                else if (v == "4")
                {
                    f.Mentes("mentett.csv");
                    Console.WriteLine("Mentve!");
                }

                // 5) Kilépés
                else if (v == "5")
                {
                    Console.WriteLine("Kilépés...");
                    break;
                }

                else
                {
                    Console.WriteLine("Érvénytelen választás!");
                }
            }
        }
    }
}