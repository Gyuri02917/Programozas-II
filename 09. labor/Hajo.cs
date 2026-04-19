using System;

namespace ZH
{
    internal abstract class Hajo
    {
        public int Eni;
        public string Nev;
        public string Tipus;
        public int Ar1;
        public int Ar2;
        public int Ar3;

        public Hajo(int eni, string nev, string tipus, int ar1, int ar2, int ar3)
        {
            Eni = eni;
            Nev = nev;
            Tipus = tipus;
            Ar1 = ar1;
            Ar2 = ar2;
            Ar3 = ar3;
        }

        public abstract int BerletiDij(int ora);

        public override string ToString()
        {
            return $"{Eni}\t{Nev}\t{Tipus}\t{Ar1}\t{Ar2}\t{Ar3}";
        }
    }
}
