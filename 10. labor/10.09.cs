using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var sor = new SorFIFO<string>();
            sor.Enqueue("Sanyika");
            sor.Enqueue("Gizike");
            sor.Enqueue("Tamáska");
            Console.WriteLine(sor.Dequeue());
            Console.WriteLine(sor.Dequeue());
            Console.WriteLine("Következő:" + sor.Peek());
        }
    }
}