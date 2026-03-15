using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ZH
{   //Dancs Sándor GEHVJL 2005.04.14 2025.10.15
    internal class Hajo
    {
        public int Kod;
        public string Nev;
        public string Tipus;
        public int ar1;
        public int ar2;
        public int ar3;

        public Hajo(int Kod, string Nev, string Tipus, int ar1, int ar2, int ar3)
        {
            this.Kod = Kod;
            this.Nev = Nev;
            this.Tipus = Tipus;
            this.ar1 = ar1;
            this.ar2 = ar2;
            this.ar3 = ar3;
        }

        public override string ToString() {
            return $"{Kod}\t{Nev}\t{Tipus}\t{ar1}\t{ar2}\t{ar3}";
        }

        public int Ar(int ora)
        {
            if (ora == 1) return ar1;
            else if (ora == 2) return ar2;
            else if (ora >= 3) return ar3*ora;
            return 0;
        }
    }
    

    
}
