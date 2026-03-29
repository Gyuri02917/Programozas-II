using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace prog2
{
    class Alap
	{
		private protected int érték = 42;
	}

	class Leszármazott : Alap
	{
		public void Kiír()
		{
			Console.WriteLine(érték); // ✔ eléri
		}
	}


	class Program
	{
		static void Main()
		{
			Leszármazott l = new Leszármazott();
			l.Kiír();
		}
	}
}
