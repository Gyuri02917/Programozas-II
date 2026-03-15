using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ZH
{   //Dancs Sándor GEHVJL 2005.04.14 2025.10.15
    internal class Flotta
    {
        public Hajo[] hajok;

        public void Beolvas(string fajl)
        {
            try
            {
                int i = 0;
                string[] sorok = File.ReadAllLines(fajl);
                hajok = new Hajo[sorok.Length-1];
                StreamReader sr = new StreamReader(fajl);
                sr.ReadLine();
                while (!sr.EndOfStream) {
                    string[] tores = sr.ReadLine().Split(';');
                    hajok[i] = new Hajo(int.Parse(tores[0]), tores[1], tores[2], int.Parse(tores[3]),int.Parse(tores[4]),int.Parse(tores[5]));
                    i++;
                }
                sr.Close();
            }
            catch (Exception ez)
            {
                Console.WriteLine("Hiba! "+ez);
            }
        }

        public void Mutat() { 
        for (int i = 0; i < hajok.Length; i++)
            {
                Console.WriteLine($"{hajok[i].Nev} - {hajok[i].Tipus}");
            }
        }

        public double AtlagAr(int ora)
        {
            int sum = 0;
            for (int i = 0;i < hajok.Length; i++)
            {
                sum += hajok[i].Ar(ora);
            }
            return sum / hajok.Length;
        }

        public Hajo Legdragabb(int ora)
        {
            int maxindex = 0;
            for (int i = 1; i < hajok.Length; i++)
            {
                if (hajok[i].Ar(ora) > hajok[maxindex].Ar(ora))
                {
                    maxindex = i;
                }
            }
            return hajok[maxindex];
        }
        public Hajo Legolcsobb(int ora)
        {
            int minindex = 0;
            for (int i = 1; i < hajok.Length; i++)
            {
                if (hajok[i].Ar(ora) < hajok[minindex].Ar(ora))
                {
                    minindex = i;
                }
            }
            return hajok[minindex];
        }

        public void SzuresTipusra(string tipus)
        {
            Console.WriteLine("A(z) {0} típusó hajók nevei:",tipus);
            for (int i = 0; i < hajok.Length; i++)
            {
                if (tipus == hajok[i].Tipus)
                {
                    Console.WriteLine(hajok[i].Nev);
                }
            }
        }

        public void SzuresArra(int MaxAr, int ora)
        {
            Console.WriteLine("A(z) {0} órára bérelhető hajók, amelyek olcsóbbak, mint {1} Ft:",ora,MaxAr);
            for (int i = 0;i < hajok.Length; i++)
            {
                if (hajok[i].Ar(ora) < MaxAr)
                {
                    Console.WriteLine(hajok[i].Nev);
                }
            }
        }

    }
}
