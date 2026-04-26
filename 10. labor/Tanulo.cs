using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Tanulo : IErtekeles
    {
        public string Nev { get; set; }
        public List<int> Jegyek { get; } = new List<int>();

        public double Atlag => Jegyek.Count == 0 ? 0 : Jegyek.Average();

        public Tanulo(string nev)
        {
            Nev = nev;
        }
    }
}
