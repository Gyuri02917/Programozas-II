using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Allat
    {
        public int ID;
        public string Faj;
        public string Nev;
        public int Eletkor;
        public int Oradij;
        public int EtelIgeny;

        public Allat(int id, string faj, string nev, int eletkor, int oradij, int etelIgeny)
        {
            ID = id;
            Faj = faj;
            Nev = nev;
            Eletkor = eletkor;
            Oradij = oradij;
            EtelIgeny = etelIgeny;
        }

        public int GondozasiKoltseg(int orak)
        {
            double alap = Oradij * orak;

            if (Eletkor > 10)
            {
                alap *= 1.2; // 20% felár
            }

            return (int)Math.Ceiling(alap);
        }

        public float NapiEtel()
        {
            return (float)EtelIgeny/100;
        }

        public override string ToString()
        {
            return $"{ID} - {Nev} ({Faj}), {Eletkor} éves, óradíj: {Oradij}, ételigény: {EtelIgeny}g";
        }
    }
}
