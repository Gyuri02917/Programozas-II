namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string szoveg = "2026";
            int ev1 = int.Parse(szoveg);
            int ev2;
            if (int.TryParse(szoveg, out ev2))
                Console.WriteLine("Siker");
            else
                Console.WriteLine("Nem sikerült");
            Console.WriteLine($"Parse: {ev1}, TryParse: {ev2}");
        }
    }
}