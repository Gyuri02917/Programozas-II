using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Diak : IComparable<Diak>
    {
        public string Nev { get; set; }
        public int Jegy { get; set; }

        public Diak(string nev, int jegy)
        {
            Nev = nev;
            Jegy = jegy;
        }

        // alapértelmezett rendezés: jegy szerint csökkenő
        public int CompareTo(Diak? other)
        {
            bool novekvo = true;
            bool jegyek = false;
            if (jegyek)
            {
                if (other == null) return 1;
                if (novekvo)
                    return other.Jegy.CompareTo(Jegy); // csökkenő (legtöbb előre)
                else
                    return Jegy.CompareTo(other.Jegy); // növekvő (legkevesebb előre)
            } else
            {
                if (other == null) return 1;
                if (novekvo)
                    return other.Nev.CompareTo(Nev);
                else
                    return Nev.CompareTo(other.Nev);
            }
        }

        public override string ToString() => $"{Nev}: {Jegy}";
    }
}
