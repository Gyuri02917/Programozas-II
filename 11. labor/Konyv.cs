using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mintaZh2a
{
    internal class Konyv : Dokumentum, IComparable<Dokumentum>
    {
        public Konyv(int a, string b, string c, int d, int e, int f) : base(a, b, c, d, e, f)
        {
            
        }

        public int CompareTo(Dokumentum? other)
        {
            if (other == null) return 1;
            return other.Ar.CompareTo(Ar);
        }

        public override int KezelesiTerheles()
        {
            return KolcsonzesiIdo * Darab;
        }

        
    }
}
