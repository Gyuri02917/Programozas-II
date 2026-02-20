namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] pontok = new int[] { 12, 11, 38, 60, 78, 15, 60, 100, 20, 12, 6, 97, 81, 45, 2, 64 };
            double atlag = 0;
            int legkisebb = pontok[0], legnagyobb = pontok[0];
            for (int i = 0; i < pontok.Length; i++)
            {
                atlag += pontok[i];
                if (pontok[i] < legkisebb)
                    legkisebb = pontok[i];
                if (pontok[i] > legnagyobb)
                    legnagyobb = pontok[i];
            }
            Console.WriteLine("A csoport pontszámai:");
            foreach (int i in pontok)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine($"A csoport átlaga: {atlag / pontok.Length}");
            Console.WriteLine($"A legkisebb pontszám: {legkisebb}");
            Console.WriteLine($"A legnagyobb pontszám: {legnagyobb}");
        }
    }
}