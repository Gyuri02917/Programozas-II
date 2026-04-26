using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<IDolgozo> dolgozok = new() //a lista elemeit közös interfészen keresztül akarjuk kezelni, ez amikor az interfész absztrakcióként működik
            {
                new Alkalmazott("Kovács János", 300000),
                new Manager("Nagy Péter", 400000, 100000)
            };
            foreach (var d in dolgozok)
                Console.WriteLine($"{d.GetType().Name}: {d.Fizetes()} Ft");
        }
    }
}