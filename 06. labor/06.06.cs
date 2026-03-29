using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace prog2
{
   class Személy
	{
		private string név;

		public string Név
		{
			get => név;
			set
			{
				if (value.Length == 0)
					throw new Exception("A név nem lehet üres!");
				név = value;
			}
		}
	}

	class Program
	{
		static void Main()
		{
			Személy s = new Személy();
			s.Név = "Tamás";
			Console.WriteLine(s.Név);
		}
	}
}
