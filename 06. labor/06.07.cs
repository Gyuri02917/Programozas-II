using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace prog2
{
   class Állat
	{
		public virtual void HangotAd()
		{
			Console.WriteLine("Valamilyen állathang...");
		}
	}

	class Kutya : Állat
	{
		public override void HangotAd()
		{
			Console.WriteLine("Vau!");
		}
	}

	class Macska : Állat
	{
		public override void HangotAd()
		{
			Console.WriteLine("Miau!");
		}
	}

	class Program
	{
		static void Main()
		{
			Állat a = new Állat();
			Állat k = new Kutya();
			Állat m = new Macska();

			a.HangotAd();
			k.HangotAd();
			m.HangotAd();
		}
	}
}
