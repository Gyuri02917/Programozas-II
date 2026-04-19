using System;
using System.Collections.Generic;
using System.IO;

namespace ZH
{
    internal class Flotta
    {
        public List<Hajo> hajok = new List<Hajo>();

        public void Beolvas(string fajl)
        {
            try
            {
                StreamReader sr = new StreamReader(fajl);
                sr.ReadLine(); // fejléc

                while (!sr.EndOfStream)
                {
                    string[] t = sr.ReadLine().Split(';');

                    int eni = int.Parse(t[0]);
                    string nev = t[1];
                    string tipus = t[2];
                    int ar1 = int.Parse(t[3]);
                    int ar2 = int.Parse(t[4]);
                    int ar3 = int.Parse(t[5]);

                    Hajo h;

                    if (tipus == "katamarán" || tipus == "új katamarán")
                    {
                        h = new Katamaran(eni, nev, tipus, ar1, ar2, ar3);
                    }
                    else if (tipus == "komp" || tipus == "új komp")
                    {
                        h = new Komp(eni, nev, tipus, ar1, ar2, ar3);
                    }
                    else if (tipus == "személyhajó")
                    {
                        h = new Szemely(eni, nev, tipus, ar1, ar2, ar3);
                    }
                    else if (tipus == "nosztalgia")
                    {
                        h = new Nosztalgia(eni, nev, tipus, ar1, ar2, ar3);
                    }
                    else
                    {
                        // opcionális fallback
                        throw new Exception("Hiba, ismeretlen típus!");
                    }


                    hajok.Add(h);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Hiba történt: " + ex.Message);
            }
        }

        public void Mutat()
        {
            foreach (var h in hajok)
                Console.WriteLine($"{h.Nev} - {h.Tipus}");
        }

        public double AtlagAr(int ora)
        {
            double sum = 0;
            foreach (var h in hajok)
                sum += h.BerletiDij(ora);

            return sum / hajok.Count;
        }

        public Hajo Legdragabb(int ora)
        {
            Hajo max = hajok[0];
            foreach (var h in hajok)
                if (h.BerletiDij(ora) > max.BerletiDij(ora))
                    max = h;

            return max;
        }

        public Hajo Legolcsobb(int ora)
        {
            Hajo min = hajok[0];
            foreach (var h in hajok)
                if (h.BerletiDij(ora) < min.BerletiDij(ora))
                    min = h;

            return min;
        }

        public void SzuresTipusra(string tipus)
        {
            Console.WriteLine($"A(z) {tipus} típusú hajók:");
            foreach (var h in hajok)
                if (h.Tipus == tipus)
                    Console.WriteLine(h.Nev);
        }

        public void SzuresArra(int maxAr, int ora)
        {
            Console.WriteLine($"{ora} órára bérelhető hajók {maxAr} Ft alatt:");
            foreach (var h in hajok)
                if (h.BerletiDij(ora) < maxAr)
                    Console.WriteLine($"{h.Nev} – {h.BerletiDij(ora)} Ft");
        }
    }
}
