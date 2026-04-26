using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var rendszer = new HallgatoiNyilvantarto();
            rendszer.DiakHozzaadas("Béla");
            rendszer.JegyRogzit("Béla", 4);
            rendszer.JegyRogzit("Béla", 5);
            rendszer.JegyRogzit("Béla", 2);
            rendszer.JegyRogzit("Béla", 2);
            rendszer.JegyRogzit("Béla", 1);
            Console.WriteLine($"Béla átlaga: {rendszer.SzamitAtlag("Béla")}");

            Console.WriteLine("Rögzített tárgyak:");
            rendszer.TantargyHozzaadas("Programozás II.");
            rendszer.TantargyHozzaadas("Villamosságtan");
            rendszer.TantargyHozzaadas("Villamosságtan");
            rendszer.TantargyakListaja();
            rendszer.Beadas("ZH1");
            rendszer.Beadas("ZH2");
            Console.WriteLine("Beadott feladatok:");
            Console.WriteLine(rendszer.Beadasok());
        }
    }
}