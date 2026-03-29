using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Flotta
    {
        public Jarmu[] Jarmuvek;

        private double? ParseDouble(string s) => s == "" ? null : double.Parse(s, CultureInfo.InvariantCulture);
        private int? ParseInt(string s) => s == "" ? null : int.Parse(s);
        private bool? ParseBool(string s) => s == "" ? null : bool.Parse(s);

        public void Beolvas(string path)
        {
            // 1) Sorok számának meghatározása (File itt még használható)
            int sorokSzama = File.ReadAllLines(path).Length;
            Jarmuvek = new Jarmu[sorokSzama-1];

            try
            {
                StreamReader sr = new StreamReader(path);

                int index = 0;
                sr.ReadLine();

                while (!sr.EndOfStream)
                {
                    string sor = sr.ReadLine();
                    string[] t = sor.Split(';');

                    int eni = int.Parse(t[0]);
                    string nev = t[1];

                    Jarmu j = new Jarmu(eni, nev);

                    j.Epult = ParseInt(t[2]);
                    j.Aktiv = ParseBool(t[3]);
                    j.Motorok = ParseInt(t[4]);

                    j.TeljesitmenyKW = ParseDouble(t[5]);
                    j.TeljesitmenyLE = ParseDouble(t[6]);

                    j.Sebesseg = ParseDouble(t[7]);
                    j.MaxUtas = ParseInt(t[8]);

                    j.Meret = new Meretek(
                        ParseDouble(t[9]),
                        ParseDouble(t[10]),
                        ParseDouble(t[11]),
                        ParseDouble(t[12]),
                        ParseDouble(t[13]),
                        ParseDouble(t[14]),
                        ParseDouble(t[15])
                    );

                    j.LeszerelesEve = ParseInt(t[16]);

                    j.SzamolTeljesitmeny();

                    Jarmuvek[index++] = j;
                }
                sr.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Hiba történt a beolvasás során: " + ex.Message);
            }
        }

        public void Mentes(string path)
        {
            using (StreamWriter sw = new StreamWriter(path))
            {
                foreach (var j in Jarmuvek)
                {
                    sw.WriteLine(
                        $"{j.ENI};{j.Nev};{j.Epult};{j.Aktiv};{j.Motorok};" +
                        $"{j.TeljesitmenyKW};{j.TeljesitmenyLE};{j.Sebesseg};{j.MaxUtas};" +
                        $"{j.Meret.LegnagyobbHossz};{j.Meret.HosszFuggely};{j.Meret.LegnagyobbSzelesseg};" +
                        $"{j.Meret.SzelessegFoborda};{j.Meret.FixpontMagassag};{j.Meret.Oldalmagassag};" +
                        $"{j.Meret.LegnagyobbMerules};{j.LeszerelesEve}"
                    );
                }
            }
        }

        public void ReszletesLista()
        {
            foreach (var j in Jarmuvek)
            {
                Console.WriteLine("\n-------------------------");
                Console.WriteLine(j.ToString());
            }
        }

        public void UjHajoFelvetele(Jarmu uj)
        {
            Jarmu[] ujTomb = new Jarmu[Jarmuvek.Length + 1];

            for (int i = 0; i < Jarmuvek.Length; i++)
                ujTomb[i] = Jarmuvek[i];

            ujTomb[ujTomb.Length - 1] = uj;
            Jarmuvek = ujTomb;
        }
    }
}
