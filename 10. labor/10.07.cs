using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Diak> diakok = new()
            {
                new Diak("Alma", 4),
                new Diak("Béla", 5),
                new Diak("Cecil", 3)
            };
            diakok.Sort();
            diakok.ForEach(Console.WriteLine);
        }
    }
}