using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Halmazok
    {
        public static HashSet<int> Metszet(List<int> l1, List<int> l2)
        {
            var set1 = new HashSet<int>(l1);
            var set2 = new HashSet<int>(l2);
            set1.IntersectWith(set2);
            return set1;
        }

        public static HashSet<int> Unio(List<int> l1, List<int> l2)
        {
            var set1 = new HashSet<int>(l1);
            set1.UnionWith(l2);
            return set1;
        }
    }
}
