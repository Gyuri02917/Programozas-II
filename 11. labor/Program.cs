namespace mintaZh2a
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Adja meg a fájl elérését: ");
            string fajl = Console.ReadLine();
            Konyvtar kk = new Konyvtar();
            kk.Beolvas(fajl);
            Console.WriteLine("\nTárolt dokumentumok:");
            kk.Listaz();
            Console.WriteLine("\nDokumentumok átlagos ára: " + kk.AtlagAr());
            Console.WriteLine("\nLegdrágább dokumentum: " + kk.Legdragabb());
            Console.WriteLine("\nA legkisebb terhelésű dokumentum: " + kk.LegkisebbTerheles());
            Console.Write("Add meg a keresett címet vagy részletét: ");
            string keres = Console.ReadLine();
            List<Dokumentum> temp = kk.KeresCimAlapjan(keres);
            foreach (Dokumentum d in temp)
            {
                Console.WriteLine(d);
            }
            Console.Write("Add meg a keresett kategóriát: ");
            keres = Console.ReadLine();
            kk.KategoriaSzerint(keres);
            Console.Write("Add meg a dokumentum típusát: (K - könyv vagy F - Folyóirat) ");
            keres= Console.ReadLine();
            Console.Write("Add meg a dokumentum ID-ját: ");
            int ID = int.Parse(Console.ReadLine());
            Console.Write("Add meg a dokumentum címét: ");
            string cim = Console.ReadLine();
            Console.Write("Add meg a dokumentum kategóriáját: ");
            string kat = Console.ReadLine();
            Console.Write("Add meg a dokumentum árát: ");
            int ar = int.Parse(Console.ReadLine());
            Console.Write("Add meg a dokumentum darabszámát: ");
            int db = int.Parse(Console.ReadLine());
            Console.Write("Add meg a dokumentum kölcsönzési idejét: ");
            int ki = int.Parse(Console.ReadLine());

            if (keres.ToUpper() == "K")
            {
                Dokumentum Temp = new Konyv(ID, cim, kat,ar,db,ki);
                kk.UjDokumentumHozzaadasa(Temp);

            } else if(keres.ToUpper() == "F")
            {
                Dokumentum Temp = new Folyoirat(ID, cim, kat, ar, db, ki);
                kk.UjDokumentumHozzaadasa(Temp);
            } else
            {
                throw new Exception("Hiba, nincs ilyen lehetőség!");
            }
            Console.Write("Adja meg a fájl mentési helyét: ");
            fajl = Console.ReadLine();
            kk.Mentes(fajl);
        }
    }
}
