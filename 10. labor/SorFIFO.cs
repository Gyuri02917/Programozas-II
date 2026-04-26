using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class SorFIFO<T>
    {
        private LinkedList<T> _elemek = new LinkedList<T>();

        public void Enqueue(T ertek)
        {
            _elemek.AddLast(ertek);
        }

        public T? Dequeue()
        {
            if (_elemek.Count == 0)
                return default;

            T elso = _elemek.First.Value;
            _elemek.RemoveFirst();
            return elso;
        }

        public T? Peek()
        {
            if (_elemek.Count == 0)
                return default;

            return _elemek.First.Value;
        }

        public int Count => _elemek.Count;
    }
}
