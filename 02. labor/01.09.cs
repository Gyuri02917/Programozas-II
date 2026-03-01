namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            int[,] matrix = new int[10, 10];

            Console.WriteLine("10x10 mátrix random számokkal (1-100):\n");
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    matrix[i, j] = rand.Next(1, 101);
                    Console.Write($"{matrix[i, j],3} ");
                }
                Console.WriteLine();
            }

            int maxErtek = matrix[0, 0];
            int maxSor = 0, maxOszlop = 0;
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    if (matrix[i, j] > maxErtek)
                    {
                        maxErtek = matrix[i, j];
                        maxSor = i;
                        maxOszlop = j;
                    }
                }
            }
            Console.WriteLine($"\nLegnagyobb elem: {maxErtek} pozíció: [{maxSor+1},{maxOszlop+1}]");

            double osszeg9 = 0;
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                osszeg9 += matrix[8, j];
            }
            double atlag9 = osszeg9 / matrix.GetLength(1);
            Console.WriteLine($"9. sor átlaga: {atlag9:F2}");

            Console.WriteLine("\n0-5 közötti lebegőpontos számok:");
            for (int i = 0; i < 5; i++)
            {
                double lebego = rand.NextDouble() * 5;  // 0.0 <= x < 5.0
                Console.WriteLine($"{lebego:F2}");
            }
        }
    }
}