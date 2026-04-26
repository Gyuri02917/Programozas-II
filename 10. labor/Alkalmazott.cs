using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Alkalmazott : IDolgozo
    {
        public string Nev { get; set; }
        public int AlapFizetes { get; set; }

        public Alkalmazott(string nev, int alap)
        {
            Nev = nev;
            AlapFizetes = alap;
        }

        public int Fizetes() => AlapFizetes;
    }
}
