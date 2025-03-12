#include <iostream>
#include <iomanip>
using namespace std;

int darab();
int* letrehoz(int);
void beker(int*, int);
void kiir(int*, int);
int otos(int*, int);
void jegyek(int*, int);

int main()
{
    setlocale(LC_ALL, "UTF-8");
	int* p;
	int n = darab();
	p = letrehoz(n);
	beker(p, n);
	cout << "Az érdemjegyek száma: " << n << endl;
	kiir(p, n);
	cout << "Az ötös érdemjegyek száma: " << otos(p, n) << endl;
	jegyek(p, n);


	delete[] p;

    return 0;
}

int darab()
{
	int n;
	cout << "Adja meg a jegyek számát: ";
	cin >> n;
	return n;
}

int* letrehoz(int db)
{
	int* t = new int[db];
	return t;
}

void beker(int* t, int db)
{
	for (int i = 0; i < db; i++)
	{
		do {
			cout << "Adja meg a(z) " << i + 1 << ". jegyet: ";
			cin >> t[i];
		} while (t[i] < 1 || t[i] > 5);
	}
}

void kiir(int* t, int db)
{
	system("cls");
	cout << "A jegyek: " << endl;
	cout.setf(ios::left);
	cout << setw(5) << "Ssz" << setw(5) << "Jegy" << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(5) << i + 1 << setw(5) << t[i] << endl;
	}
	cout << endl;
}

int otos(int* t, int db)
{
	int db5 = 0;
	for (int i = 0; i < db; i++)
	{
		if (t[i] == 5)
		{
			db5++;
		}
	}
	return db5;
}

void jegyek(int* t, int db)
{
	int* jegy = new int[5];
	for (int i = 0; i < 5; i++)
	{
		jegy[i] = 0;
	}
	for (int i = 0; i < db; i++)
	{
		switch (t[i])
		{
		case 1:
		{
			jegy[0]++;
			break;
		}
		case 2:
		{
			jegy[1]++;
			break;
		}
		case 3:
		{
			jegy[2]++;
			break;
		}
		case 4:
		{
			jegy[3]++;
			break;
		}
		case 5:
		{
			jegy[4]++;
			break;
		}
		}
	}
	for (int i = 0; i < 5;i++)
	{
		cout << i + 1 << "-es: " << jegy[i] << " db" << endl;
	}
}