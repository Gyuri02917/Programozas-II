namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string path = "adatok.csv";
            
            // File osztály használata
            if (File.Exists(path))
            {
                // 1. Egyszerű ReadAllLines - fejléccel együtt
                string[] osszesSor = File.ReadAllLines(path);
                
                Console.WriteLine("=== FILE.OSZTÁLY - ReadAllLines ===");
                Console.WriteLine($"Sorok száma (fejléc+adatok): {osszesSor.Length}");
                
                // Fejléc kihagyása (1. sor)
                for (int j = 1; j < osszesSor.Length; j++)
                {
                    string[] ss = osszesSor[j].Split(',');
                    if (ss.Length > 6)
                        Console.WriteLine($"Nyomtató: {ss[0]}, Típus: {ss[1]}, Anyagok: {ss[6]}");
                }
                
                Console.WriteLine();
                
                // 2. CSV speciális kezelés TextFieldParser-rel (Microsoft.VisualBasic)
                Console.WriteLine("=== FILE + TextFieldParser (CSV) ===");
                using (TextFieldParser parser = new TextFieldParser(path))
                {
                    parser.TextFieldType = FieldType.Delimited;
                    parser.SetDelimiters(",");
                    parser.HasFieldsEnclosedInQuotes = true;
                    
                    // Fejléc kihagyása
                    parser.ReadFields();
                    
                    while (!parser.EndOfData)
                    {
                        string[] ss = parser.ReadFields();
                        if (ss.Length > 6)
                            Console.WriteLine($"Nyomtató: {ss[0]}, Típus: {ss[1]}, Anyagok: {ss[6]}");
                    }
                }
            }
            else
            {
                Console.WriteLine("adatok.csv nem található!");
            }
        }
    }
}
