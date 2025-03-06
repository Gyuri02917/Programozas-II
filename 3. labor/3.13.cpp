#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Feltolt(int[], int n);
void Kiir(int[], int);
int Max(int[], int);

int main()
{
	setlocale(LC_ALL, "UTF-8");
	srand((unsigned)time(NULL));
	int db;
	do {
		cout << "Hány tanuló jár a csoportba? ";
		cin >> db;
	} while (db > 10 || db < 1);

	int* pontok = new int[db];
	Feltolt(pontok, db);
	Kiir(pontok, db);
	cout << "A legjobb pontok: " << Max(pontok, db) << endl;
	delete[] pontok;

	return 0;
}

void Feltolt(int pontok[], int n)
{
	for (int i = 0; i < n; i++)
	{
		pontok[i] = rand() % 100 + 1;
	}
}

void Kiir(int pontok[], int n)
{
	cout << "A csoport pontjai: ";
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << pontok[i];
	}
	cout << endl;
}

int Max(int pontok[], int n)
{
	int max = pontok[0];
	for (int i = 1; i < n; i++)
	{
		if (pontok[i] > max)
		{
			max = pontok[i];
		}
	}
	return max;
}