namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int zh1, zh2;
            Console.Write("Add meg az 1. zh eredményét: ");
            zh1 = int.Parse(Console.ReadLine());
            Console.Write("Add meg a 2. zh eredményét: ");
            zh2 = int.Parse(Console.ReadLine());

            if (zh1 + zh2 > 85)
                Console.WriteLine("Jeles - 5");
            else if (zh1 + zh2 > 75)
                Console.WriteLine("Jó - 4");
            else if (zh1 + zh2 > 60)
                Console.WriteLine("Közepes - 3");
            else if (zh1 + zh2 > 49)
                Console.WriteLine("Elégséges - 2");
            else
                Console.WriteLine("Elégtelen - 1");
        }
    }
}