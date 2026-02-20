namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int dobas;
            Console.Write("Adja meg a dobott számot (1-6): ");
            dobas = int.Parse(Console.ReadLine());

            switch (dobas)
            {
                case 1:
                    Console.WriteLine("A dobott érték: 1"); break;
                case 2:
                    Console.WriteLine("A dobott érték: 2"); break;
                case 3:
                    Console.WriteLine("A dobott érték: 3"); break;
                case 4:
                    Console.WriteLine("A dobott érték: 4"); break;
                case 5:
                    Console.WriteLine("A dobott érték: 5"); break;
                case 6:
                    Console.WriteLine("A dobott érték: 6"); break;
                default:
                    Console.WriteLine("Hibás érték!"); break;
            }
        }
    }
}