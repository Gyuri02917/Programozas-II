using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var szoveg = "alma korte alma korte alma";
            var gyak = Szogya.SzotarEpit(szoveg);
            foreach (var kvp in gyak)
                Console.WriteLine($"{kvp.Key}: {kvp.Value}");
        }
    }
}