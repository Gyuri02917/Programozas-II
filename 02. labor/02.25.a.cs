using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string path = "adatok.csv";
            StreamReader sr = new StreamReader(path);
            string[] sorok = new string[50];
            int i = 0;
            sr.ReadLine(); //Fejléc eldobása
            while (!sr.EndOfStream)
            {
                sorok[i] = sr.ReadLine();
                i++;
            }
            sr.Close();
            Console.WriteLine("A beolvasott adatok:");
            for(int j=0;j<i;j++)
            {
                string[] ss = sorok[j].Split(',');
                Console.WriteLine($"Nyomtató neve: {ss[0]}, típusa: {ss[1]}, támogatott anyagok: {ss[6]}");
            }
        }
    }
}
