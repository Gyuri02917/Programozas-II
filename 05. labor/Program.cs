using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Add meg a beolvasandó fájl nevét: ");
            string fajl = Console.ReadLine();

            Menhely m = new Menhely();
            m.Beolvas(fajl);

            while (true)
            {
                Console.WriteLine("\n--- Állatmenhely Menü ---");
                Console.WriteLine("1. Állatok listázása");
                Console.WriteLine("2. Átlagéletkor");
                Console.WriteLine("3. Legmagasabb gondozási költség");
                Console.WriteLine("4. Legalacsonyabb ételigény");
                Console.WriteLine("5. Keresés névrészlet alapján");
                Console.WriteLine("6. Szűrés faj szerint");
                Console.WriteLine("7. Új állat felvétele");
                Console.WriteLine("8. Mentés fájlba");
                Console.WriteLine("9. Kilépés");
                Console.Write("Választás: ");

                int valasztas;
                int.TryParse(Console.ReadLine(), out valasztas);
                Console.Clear();
                switch (valasztas)
                {
                    case 1:
                        m.Listaz();
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 2:
                        Console.WriteLine("Átlagéletkor: " + m.AtlagEletkor());
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 3:
                        Console.Write("Hány órára számoljuk? ");
                        int orak = int.Parse(Console.ReadLine());
                        Console.WriteLine("Legdrágább: " + m.LegmagasabbKoltseg(orak));
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 4:
                        Console.WriteLine("Legalacsonyabb ételigény: " + m.LegalacsonyabbEteligeny());
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 5:
                        Console.Write("Névrészlet: ");
                        string reszlet = Console.ReadLine();
                        m.KeresNevAlapjan(reszlet);
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 6:
                        Console.Write("Faj: ");
                        string faj = Console.ReadLine();
                        m.FajSzerint(faj);
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 7:
                        Console.Write("Új állat neve: ");
                        string nev = Console.ReadLine();

                        Console.Write("Faj: ");
                        string ujFaj = Console.ReadLine();

                        Console.Write("Életkor: ");
                        int eletkor = int.Parse(Console.ReadLine());

                        Console.Write("Óradíj: ");
                        int oradij = int.Parse(Console.ReadLine());

                        Console.Write("Ételigény (g): ");
                        int etel = int.Parse(Console.ReadLine());

                        Random rnd = new Random();
                        int id = rnd.Next(1000, 9999);

                        Allat uj = new Allat(id, ujFaj, nev, eletkor, oradij, etel);
                        m.UjAllatHozzaadasa(uj);

                        Console.WriteLine("Állat hozzáadva!");
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 8:
                        Console.Write("Mentés fájl neve: ");
                        string ment = Console.ReadLine();
                        m.Mentes(ment);
                        Console.WriteLine("Mentve!");
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 9:
                        return;

                    default:
                        Console.WriteLine("Érvénytelen választás.");
                        Console.ReadKey();
                        Console.Clear();
                        break;
                }
            }
        }
    }
}