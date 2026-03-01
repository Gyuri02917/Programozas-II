using Microsoft.VisualBasic.FileIO;

namespace prog2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            EmailKereso("Kapcsolat: info@nje.hu, telefon: +36 30 123 4567");
            EmailKereso("Kiss Pista, Ádánd, +36 20 123 4567");
            EmailKereso("Nincs email cím itt, csak telefon: 06 30 111 2222");
            EmailKereso("Email: user@gmail.com");
        }

        static void EmailKereso(string bemenet)
        {
            int atJel = bemenet.IndexOf('@');

            if (atJel > 0 && atJel < bemenet.Length - 1)
            {
                int kezd = atJel;
                while (kezd > 0 && !char.IsWhiteSpace(bemenet[kezd - 1]) && bemenet[kezd - 1] != ',' && bemenet[kezd - 1] != ':' && bemenet[kezd - 1] != ';')
                {
                    kezd--;
                }

                int vege = atJel + 1;
                while (vege < bemenet.Length && !char.IsWhiteSpace(bemenet[vege]) && bemenet[vege] != ',' && bemenet[vege] != '.' && bemenet[vege] != ';')
                {
                    vege++;
                }

                string email = bemenet.Substring(kezd, vege - kezd);
                Console.WriteLine($"Email cím: {email}");
            }
            else
            {
                Console.WriteLine("Elérhetőség nem található!");
            }
        }
    }
}