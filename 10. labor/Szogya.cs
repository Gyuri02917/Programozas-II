using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Szogya
    {
        public static Dictionary<string, int> SzotarEpit(string szoveg)
        {
            var freq = new Dictionary<string, int>();
            string[] szavak = szoveg
                .ToLower()
                .Split(new char[] { ' ', '\t', '\n', '\r', '.', ',', '!', '?' },
                       StringSplitOptions.RemoveEmptyEntries);

            foreach (string s in szavak)
            {
                if (freq.ContainsKey(s))
                    freq[s]++;
                else
                    freq[s] = 1;
            }

            return freq;
        }
    }
}
