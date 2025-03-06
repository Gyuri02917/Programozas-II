#include <iostream>
using namespace std;

void beker(int* t, int db);
float kiir(int* t, int db);
void rendez(int* t, int db);

int main()
{
	setlocale(LC_ALL, "UTF-8");
	int* tmb, lsz, atlag;
	do {
		cout << "Adja meg a csoport létszámát: ";
		cin >> lsz;
	} while (lsz < 1 || lsz > 15);

	tmb = new int[lsz];
	beker(tmb, lsz);
	system("cls");
	cout << "Magasságok: ";
	cout << "A csoport átlagos magassága: " << kiir(tmb, lsz) << endl;
	cout << "A csoport tagjainak magassága növekvő sorrendben: ";
	rendez(tmb, lsz);
	kiir(tmb, lsz);
	delete[] tmb;

	return 0;
}

void beker(int* t, int db)
{
	for (int i = 0; i < db; i++)
	{
		cout << "Adja meg a " << i + 1 << ". személy magasságát: ";
		cin >> t[i];
	}
}

float kiir(int* t, int db)
{
	float atlag = 0;
	for (int i = 0; i < db; i++)
	{
		atlag += t[i];
		cout << t[i] << ", ";
	}

	return atlag / db;
}

void rendez(int* t, int db)
{
	for (int i = 0; i < db - 1; i++)
	{
		for (int j = i + 1; j < db; j++)
		{
			if (t[i] > t[j])
			{
				int csere;
				csere = t[i];
				t[i] = t[j];
				t[j] = csere;
			}
		}
	}
}