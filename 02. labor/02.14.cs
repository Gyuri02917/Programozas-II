namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string szoveg = "A gépi látás területén ma már meghatározóak a gépi tanulás alapú Deep Learning megoldások, azokon belül is a Convolutional Neural Network és Vision Transformer modellek. Egy-egy konkrét osztályozási vagy objektumdetekciós feladatra a megfelelő modell megtalálása és feltanítása fontos feladat. A kutatási feladatban a részfeladatok: különböző CNN, ViT, Transfer Learning és AutoML módszer megismerésére, tanító adathalmaz gyűjtése és címkézése, modellek feltanítása és kiértékelése.";

            int gepiLatasPos = szoveg.IndexOf("gépi látás");
            Console.WriteLine($"\"gépi látás\" pozíciója: {gepiLatasPos}");

            Console.WriteLine($"String hossza: {szoveg.Length} karakter");

            string csereUtani = szoveg.Replace("CNN", "Convolutional Neural Network");
            Console.WriteLine("\nCNN cserélve:");
            Console.WriteLine(csereUtani);

            string[] szavak = szoveg.Split(' ', StringSplitOptions.RemoveEmptyEntries);
            Console.WriteLine($"\nSzavak száma: {szavak.Length}");
            Console.WriteLine("Első 10 szó:");
            for (int i = 0; i < Math.Min(10, szavak.Length); i++)
            {
                Console.WriteLine($"  {i}: \"{szavak[i]}\"");
            }

            Console.WriteLine($"\nTeljes statisztika:");
            Console.WriteLine($"- Karakterek: {szoveg.Length}");
            Console.WriteLine($"- Szavak: {szavak.Length}");
        }
    }
}
