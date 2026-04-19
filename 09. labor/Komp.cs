namespace ZH
{
	internal class Nosztalgia : Hajo
    {
        public Nosztalgia(int eni, string nev, string tipus, int ar1, int ar2, int ar3)
            : base(eni, nev, tipus, ar1, ar2, ar3) { }

        public override int BerletiDij(int ora)
        {
            if (ora == 1) return Ar1;
            if (ora == 2) return 2 * Ar2;
            return ora * Ar3;
        }
    }
}
