namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[,] sakk = new int[8, 8];

            for (int sor = 0; sor < sakk.GetLength(0); sor++)
            {
                for (int oszlop = 0; oszlop < sakk.GetLength(1); oszlop++)
                {
                    sakk[sor, oszlop] = (sor + oszlop) % 2;
                }
            }

            Console.WriteLine("Sakktábla (0=fekete, 1=fehér):");
            for (int sor = 0; sor < sakk.GetLength(0); sor++)
            {
                for (int oszlop = 0; oszlop < sakk.GetLength(1); oszlop++)
                {
                    Console.Write($"{sakk[sor, oszlop]} ");
                }
                Console.WriteLine();
            }

            int fekete = 0, feher = 0;
            for (int sor = 0; sor < sakk.GetLength(0); sor++)
            {
                for (int oszlop = 0; oszlop < sakk.GetLength(1); oszlop++)
                {
                    if (sakk[sor, oszlop] == 0) fekete++;
                    else feher++;
                }
            }
            Console.WriteLine($"\nFekete mezők (0): {fekete}");
            Console.WriteLine($"Fehér mezők (1): {feher}");
            Console.WriteLine($"Magasság: {sakk.GetLength(0)} sor");
            Console.WriteLine($"Szélesség: {sakk.GetLength(1)} oszlop");
            Console.Write("3. sor elemei: ");
            for (int oszlop = 0; oszlop < sakk.GetLength(1); oszlop++)
            {
                Console.Write($"{sakk[3, oszlop]} ");
            }
            Console.WriteLine();
        }
    }
}