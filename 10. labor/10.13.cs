using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var l1 = new List<int> { 1, 2, 3 };
            var l2 = new List<int> { 2, 3, 4 };
            var metszet = Halmazok.Metszet(l1, l2);
            Console.Write("Két halmaz metszete: ");
            foreach (var x in metszet)
                Console.Write(x + " ");
            Console.WriteLine();
        }
    }
}