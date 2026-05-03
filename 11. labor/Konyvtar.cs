using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mintaZh2a
{
    internal class Konyvtar
    {
        public List<Dokumentum> dokumentumok = new List<Dokumentum>();

        public void Beolvas(string fajl)
        {
            try
            {
                StreamReader sr = new StreamReader(fajl);
                while (!sr.EndOfStream)
                {
                    string sor = sr.ReadLine();
                    string[] r = sor.Split(';');

                    if (r[0] == "F")
                    {
                        dokumentumok.Add(new Folyoirat(int.Parse(r[1]), r[2], r[3], int.Parse(r[4]), int.Parse(r[5]), int.Parse(r[6])));
                    }
                    else if (r[0] == "K")
                    {
                        dokumentumok.Add(new Konyv(int.Parse(r[1]), r[2], r[3], int.Parse(r[4]), int.Parse(r[5]), int.Parse(r[6])));
                    }
                }
                sr.Close();
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("Hiba, a megadott fájl nem található!");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Hiba: " + ex.Message);
            }
        }

        public void Listaz()
        {
            foreach (var d in dokumentumok)
                Console.WriteLine(d);
        }

        public double AtlagAr()
        {
            double ar = 0;
            foreach(var d in dokumentumok)
            {
                ar += d.Ar;
            }
            return ar/dokumentumok.Count();
        }

        public Dokumentum Legdragabb()
        {
            int ix = 0;
            for (int i = 1; i < dokumentumok.Count(); i++)
            {
                if (dokumentumok[i].Ar > dokumentumok[ix].Ar)
                    ix = i;
            }
            return dokumentumok[ix];
        }
        public Dokumentum LegkisebbTerheles()
        {
            int ix = 0;
            for (int i = 1; i < dokumentumok.Count(); i++)
            {
                if (dokumentumok[i].KezelesiTerheles() > dokumentumok[ix].KezelesiTerheles())
                    ix = i;
            }
            return dokumentumok[ix];
        }

        public List<Dokumentum> KeresCimAlapjan(string reszlet)
        {
            List<Dokumentum> temp = new List<Dokumentum>();
            foreach (var d in dokumentumok)
            {
                if(d.Cim.ToLower().Contains(reszlet.ToLower()))
                {
                    temp.Add(d);
                }
            }
            return temp;
        }

        public void KategoriaSzerint(string kateg)
        {
            foreach(var d in dokumentumok)
                if(d.Kategoria.ToLower() == kateg.ToLower())
                    Console.WriteLine(d);
        }

        public void UjDokumentumHozzaadasa(Dokumentum temp)
        {
            dokumentumok.Add(temp);
        }

        public void RendezArSzerint()
        {
            dokumentumok.Sort();
        }

        public void Mentes(string fajl)
        {
            try
            {
                StreamWriter sw = new StreamWriter(fajl);
                foreach (var d in dokumentumok)
                    sw.WriteLine(d);
                sw.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Hiba a fájl írásakor: " + ex.Message);
            }
        }
    }
}