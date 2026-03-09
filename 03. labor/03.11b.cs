namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string path = "adatok.txt";
            
            // File osztály használata
            if (File.Exists(path))
            {
                // 1. Egyszerű ReadAllLines - fejléccel együtt
                string[] osszesSor = File.ReadAllLines(path);
                
                Console.WriteLine("=== FILE.OSZTÁLY - ReadAllLines ===");
                Console.WriteLine($"Sorok száma (fejléc+adatok): {osszesSor.Length}");
                
                // Fejléc kihagyása (1. sor)
                for (int j = 1; j < osszesSor.Length; j++)
                {
                    string[] ss = osszesSor[j].Split(';');
                    if (ss.Length >= 3)
                        Console.WriteLine($"Hajó neve: {ss[1]}, besorolása: {ss[2]}, azonosítója: {ss[0]}");
                }
                
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine("adatok.txt nem található!");
            }
        }
    }
}
