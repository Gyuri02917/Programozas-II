namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Abs()
            double absz = -20.5;
            Console.WriteLine($"{absz} abszolút értéke: {Math.Abs(absz)}");
            //Ceiling()
            double kerekfel = 12.6;
            Console.WriteLine($"{kerekfel} felkerekített egész értéke: {Math.Ceiling(kerekfel)}");
            //Floor()
            double kerekle = 15.6;
            Console.WriteLine($"{kerekle} felkerekített egész értéke: {Math.Floor(kerekle)}");
            //Round()
            double kerek = 7.88912354;
            Console.WriteLine($"{kerek} értéke egészre kerekítés után: {Math.Round(kerek)}");
            Console.WriteLine($"{kerek} értéke 2 tizedesre kerekítés után: {Math.Round(kerek,2)}");
            //Sin()
            int szinusz = 120;
            Console.WriteLine($"{szinusz} sin utáni értéke: {Math.Sin(szinusz)}");
            //Cos()
            int koszinusz = 15;
            Console.WriteLine($"{koszinusz} cos utáni értéke: {Math.Cos(koszinusz)}");
            //Tan()
            int tangens = 160;
            Console.WriteLine($"{tangens} tan utáni értéke: {Math.Tan(tangens)}");
            //Log()
            int logE = 1234;
            Console.WriteLine($"{logE} természetes logaritmusa: {Math.Log(logE)}");
            //Log10()
            int log10 = 1000;
            Console.WriteLine($"{log10} 10-es alapú logaritmusa: {Math.Log10(log10)}");
            //Min()
            int mini = -160;
            int maxi = 160;
            Console.WriteLine($"{mini} és {maxi} közül a kisebb: {Math.Min(mini, maxi)}");
            //Max()
            Console.WriteLine($"{mini} és {maxi} közül a nagyobb: {Math.Max(mini, maxi)}");
            //Pow()
            int hatvanyAlap = 2;
            int hatvanyKitevo = 16;
            Console.WriteLine($"{hatvanyAlap} a {hatvanyKitevo}-re emelve: {Math.Pow(hatvanyAlap, hatvanyKitevo)}");
            //Sqrt()
            int gyok = 160;
            Console.WriteLine($"{gyok} négyzetgyöke: {Math.Sqrt(gyok)}");
            //PI()
            Console.WriteLine($"PI értéke: {Math.PI}");
            //E()
            Console.WriteLine($"E értéke: {Math.E}");
        }
    }
}