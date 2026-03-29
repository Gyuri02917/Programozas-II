using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace prog2
{
    static class Matematika
	{
		public static double PI = 3.14159;

		public static double Kerület(double r)
		{
			return 2 * PI * r;
		}
	}

	class Program
	{
		static void Main()
		{
			Console.WriteLine(Matematika.Kerület(10));
		}
	}
}
