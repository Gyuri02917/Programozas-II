using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class HallgatoiNyilvantarto
    {
        private Dictionary<string, List<int>> jegyek = new();
        private HashSet<string> targyak = new();
        private LinkedList<string> beadottFeladatok = new(); // FIFO sorrend

        public void DiakHozzaadas(string nev)
        {
            if (!jegyek.ContainsKey(nev))
                jegyek[nev] = new List<int>();
        }

        public void JegyRogzit(string nev, int jegy)
        {
            if (!jegyek.ContainsKey(nev))
                DiakHozzaadas(nev);

            jegyek[nev].Add(jegy);
        }

        public double SzamitAtlag(string nev)
        {
            if (!jegyek.TryGetValue(nev, out var lista) || lista.Count == 0)
                return 0;

            return lista.Average();
        }

        public Tanulo LegjobbDiak()
        {
            Tanulo legjobb = null;
            double maxAtlag = -1;

            foreach (var kvp in jegyek)
            {
                var diak = new Tanulo(kvp.Key);
                diak.Jegyek.AddRange(kvp.Value);
                double atlag = diak.Atlag;

                if (atlag > maxAtlag)
                {
                    legjobb = diak;
                    maxAtlag = atlag;
                }
            }

            return legjobb;
        }

        public HashSet<string> Tantargyak => targyak;

        public void TantargyHozzaadas(string nev)
        {
            targyak.Add(nev);
        }

        public void TantargyakListaja()
        {
            foreach(var targy in targyak)
                Console.WriteLine("- "+targy);
        }

        public void Beadas(string feladatNev)
        {
            beadottFeladatok.AddLast(feladatNev);
        }

        public string Beadasok()
        {
            return string.Join(" → ", beadottFeladatok);
        }
    }
}
