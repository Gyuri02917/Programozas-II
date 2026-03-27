using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace prog2
{
    internal class Menhely
    {
        public Allat[] allatok;

        public void Beolvas(string fajlnev)
        {
            try
            {
                string[] sorok = File.ReadAllLines(fajlnev);
                allatok = new Allat[sorok.Length];

                for (int i = 0; i < sorok.Length; i++)
                {
                    string[] adat = sorok[i].Split(';');

                    int id = int.Parse(adat[0]);
                    string faj = adat[1];
                    string nev = adat[2];
                    int eletkor = int.Parse(adat[3]);
                    int oradij = int.Parse(adat[4]);
                    int etel = int.Parse(adat[5]);

                    allatok[i] = new Allat(id, faj, nev, eletkor, oradij, etel);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Hiba történt a beolvasás során: " + ex.Message);
            }
        }

        public void Listaz()
        {
            foreach (var a in allatok)
            {
                Console.WriteLine($"{a.Nev} - {a.Faj} - {a.Eletkor} éves");
            }
        }

        public double AtlagEletkor()
        {
            double ossz = 0;

            foreach (var a in allatok)
            {
                ossz += a.Eletkor;
            }

            return ossz / allatok.Length;
        }

        public Allat LegmagasabbKoltseg(int orak)
        {
            Allat max = allatok[0];

            foreach (var a in allatok)
            {
                if (a.GondozasiKoltseg(orak) > max.GondozasiKoltseg(orak))
                {
                    max = a;
                }
            }

            return max;
        }

        public Allat LegalacsonyabbEteligeny()
        {
            Allat min = allatok[0];

            foreach (var a in allatok)
            {
                if (a.NapiEtel() < min.NapiEtel())
                {
                    min = a;
                }
            }

            return min;
        }

        public void KeresNevAlapjan(string reszlet)
        {
            bool van = false;
            foreach (var a in allatok)
            {
                if (a.Nev.ToLower().Contains(reszlet.ToLower()))
                {
                    van = true;
                    Console.WriteLine(a);
                }
            }
            Console.WriteLine(van?"":"Nincs találat!");
        }

        public void FajSzerint(string faj)
        {
            foreach (var a in allatok)
            {
                if (a.Faj.ToLower() == faj.ToLower())
                {
                    Console.WriteLine(a);
                }
            }
        }

        public void UjAllatHozzaadasa(Allat uj)
        {
            Allat[] ujTomb = new Allat[allatok.Length + 1];

            for (int i = 0; i < allatok.Length; i++)
            {
                ujTomb[i] = allatok[i];
            }

            ujTomb[ujTomb.Length - 1] = uj;
            allatok = ujTomb;
        }

        public void Mentes(string fajlnev)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter(fajlnev))
                {
                    foreach (var a in allatok)
                    {
                        sw.WriteLine($"{a.ID};{a.Faj};{a.Nev};{a.Eletkor};{a.Oradij};{a.EtelIgeny}");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Hiba történt a mentés során: " + ex.Message);
            }
        }
    }
}
