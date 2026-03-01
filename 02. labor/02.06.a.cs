namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] haromszog = new int[15];

            for (int i = 0; i < haromszog.Length; i++)
            {
                int n = i + 1;  // 1-től 15-ig
                haromszog[i] = n * (n + 1) / 2;
            }

            Console.WriteLine($"14. elem (index 14): {haromszog[14]}");
            Console.WriteLine($"Tömb hossza: {haromszog.Length}");
            Console.WriteLine("Páros indexű elemek:");
            for (int i = 0; i < haromszog.Length; i += 2)
            {
                Console.WriteLine($"Index {i}: {haromszog[i]}");
            }
            Console.WriteLine("\nTeljes tömb:");
            for (int i = 0; i < haromszog.Length; i++)
            {
                Console.Write($"{haromszog[i]} ");
            }
        }
    }
}
