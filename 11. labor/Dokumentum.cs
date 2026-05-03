using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mintaZh2a
{
    abstract class Dokumentum
    {
        public int ID;
        public string Cim;
        public string Kategoria;
        public int Ar;
        public int Darab;
        public int KolcsonzesiIdo;

        protected Dokumentum(int a, string b, string c, int d, int e, int f)
        {
            ID = a;
            Cim = b;
            Kategoria = c;
            Ar = d;
            Darab = e;
            KolcsonzesiIdo = f;
        }

        public int Osszertek()
        {
            return Ar * Darab;
        }

        public abstract int KezelesiTerheles();

        public override string ToString()
        {
            return $"{Cim} - {Kategoria} ({ID}), Ára: {Ar} Ft, kölcsönzési idő: {KolcsonzesiIdo} nap, darab: {Darab}";
        }
    }
}
