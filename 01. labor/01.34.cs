namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //1. feladat
            int fakt;
            do
            {
                Console.Write("Adjon meg egy pozitív egész számot: ");
                fakt = int.Parse(Console.ReadLine());
            } while (fakt < 0);
            int faktOsszeg = 1;
            for (int i = fakt; i > 0; i--)
                faktOsszeg *= i;
            Console.WriteLine($"{fakt}! = {faktOsszeg}");

            //2. feladat
            Console.Write("Adja meg a Fibonacci-sorozat hosszát: ");
            int fibonacci = int.Parse(Console.ReadLine());
            int fib0 = 1, fib1 = 1;

            Console.Write("1 1 ");

            for (int i = 2; i < fibonacci; i++)
            {
                int fibKov = fib0 + fib1;
                fib0 = fib1;
                fib1 = fibKov;
                Console.Write(fibKov + " ");
            }
            Console.WriteLine();

            //3. feladat
            Console.Write("Adja meg a tömb méretét: ");
            int meret = int.Parse(Console.ReadLine());

            int[] tomb = new int[meret];

            for (int i = 0; i < meret; i++)
            {
                int szam;
                do
                {
                    Console.Write($"Adja meg a {i + 1}. számot (0-100): ");
                    szam = int.Parse(Console.ReadLine());
                }
                while (szam < 0 || szam > 100);

                tomb[i] = szam;
            }

            Console.Write("Tömb tartalma: ");
            foreach (int elem in tomb)
            {
                Console.Write(elem + " ");
            }
            Console.WriteLine();

            //4. feladat
            bool jobbra = true;  // true=jobbra, false=balra
            int aktualisJatekos = 0;
            int jatekosokSzama = 7;

            Console.WriteLine("Buggy egy, jobbra megy! (Enter gombnyomásra lépjen)");

            int ertek = 0;
            while (true)
            {
                Console.ReadKey(true);

                ertek++;

                // 7-es szabály ellenőrzése
                bool buggy = (ertek % 10 == 7) || (ertek % 7 == 0);

                // Megfordítás Buggy után
                if (buggy)
                {
                    jobbra = !jobbra;
                    Console.Write($"Buggy ");
                }
                else
                {
                    Console.Write($"{ertek} ");
                }

                // Játékos mozgása + irányjel
                aktualisJatekos = (aktualisJatekos + (jobbra ? 1 : -1) + jatekosokSzama) % jatekosokSzama;
                Console.Write(jobbra ? "j " : "b ");

                if (ertek >= 19) break;
            }

            Console.WriteLine("\n--- Vége ---");
        }
    }
}