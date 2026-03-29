using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace prog2
{
   enum Napok { Hétfő, Kedd, Szerda, Csütörtök, Péntek, Szombat, Vasárnap }

	class Program
	{
		static void Main()
		{
			Console.Write("Adj meg egy napot: ");
			string input = Console.ReadLine();

			if (Enum.TryParse(input, out Napok nap))
			{
				if (nap == Napok.Szombat || nap == Napok.Vasárnap)
					Console.WriteLine("Hétvége!");
				else
					Console.WriteLine("Hétköznap.");
			}
			else
			{
				Console.WriteLine("Nincs ilyen nap!");
			}
		}
	}
}
