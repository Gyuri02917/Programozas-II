namespace ZH
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Dancs Sándor GEHVJL 2005.04.14 2025.10.15
            Console.WriteLine("Adja meg a fájl elérését:");
            string fajlnev=Console.ReadLine();
            Flotta f = new Flotta();
            f.Beolvas(fajlnev);
            int oraszam = 0;
            string hajotipus;
            int maxar = 0;
            while (true)
            {
                Console.WriteLine("Válasszon az alábbiak közül:");
                Console.WriteLine("1 - Hajók listázása");
                Console.WriteLine("2 - Átlagár számítása adott időre");
                Console.WriteLine("3 - Legdrágább hajó adott időre");
                Console.WriteLine("4 - Legolcsóbb hajó adott időre");
                Console.WriteLine("5 - Szűrés típus alapján");
                Console.WriteLine("6 - Szűrés ár alapján adott időre");
                Console.WriteLine("0 - Kilépés");
                int valasztas=int.Parse(Console.ReadLine());
                switch (valasztas)
                {
                    case 0: return;
                    case 1: f.Mutat(); break;
                    case 2:
                        Console.WriteLine("Adja meg a bérlési időt:");                      
                        oraszam=int.Parse(Console.ReadLine());
                        Console.WriteLine("A flotta átlagára: "+ f.AtlagAr(oraszam));
                        break;

                    case 3:
                        Console.WriteLine("Adja meg a bérlési időt:");
                        oraszam= int.Parse(Console.ReadLine());
                        Console.WriteLine("Legdrágább hajó adott időre: {0}, költsége: {1}",f.Legdragabb(oraszam).Nev,f.Legdragabb(oraszam).Ar(oraszam));
                        break;

                    case 4:
                        Console.WriteLine("Adja meg a bérlési időt:");
                        oraszam = int.Parse(Console.ReadLine());
                        Console.WriteLine("Legolcsóbb hajó adott időre: {0}, költsége: {1}", f.Legolcsobb(oraszam).Nev, f.Legolcsobb(oraszam).Ar(oraszam));
                        break;

                    case 5:
                        Console.WriteLine("Adja meg a bérelni kívánt hajó típusát:");
                        hajotipus=Console.ReadLine();
                        f.SzuresTipusra(hajotipus);
                        break;

                    case 6:
                        Console.WriteLine("Adja meg a max árat:");
                        maxar=int.Parse(Console.ReadLine());
                        Console.WriteLine("Adja meg a bérlési időt:");
                        oraszam = int.Parse(Console.ReadLine());
                        f.SzuresArra(maxar, oraszam);
                        break;




                    default:
                        break;
                }
            }
        }
    }
}
