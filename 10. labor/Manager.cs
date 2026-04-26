using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Manager : IDolgozo
    {
        public string Nev { get; set; }
        public int AlapFizetes { get; set; }
        public int Bonusz { get; set; }

        public Manager(string nev, int alap, int bonusz)
        {
            Nev = nev;
            AlapFizetes = alap;
            Bonusz = bonusz;
        }

        public int Fizetes() => AlapFizetes + Bonusz;
    }
}
