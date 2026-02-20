namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int szam1 = 5;
            int szam2 = 120;
            double maradekNelkul = szam1 / szam2; //0-t fogunk kapni
            double maradekCastolas = (double)szam1 / szam2;
            double maradekConvert = Convert.ToDouble(szam1) / szam2;
            Console.WriteLine($"Maradék nélküli eset: {maradekNelkul}");
            Console.WriteLine($"Castolás esetén: {maradekCastolas}");
            Console.WriteLine($"Konvertálás esetén: {maradekConvert}");
        }
    }
}