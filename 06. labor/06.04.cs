using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace prog2
{
   struct Diák
	{
		public string Név;
		public int Életkor;
		public string Lakhely;

		public void Kiír()
		{
			Console.WriteLine($"{Név}, {Életkor} éves, lakhely: {Lakhely}");
		}
	}

	class Program
	{
		static void Main()
		{
			Diák d1 = new Diák { Név = "Anna", Életkor = 20, Lakhely = "Kecskemét" };
			Diák d2 = new Diák { Név = "Béla", Életkor = 22, Lakhely = "Szeged" };

			d1.Kiír();
			d2.Kiír();
		}
	}
}
