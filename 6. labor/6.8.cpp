#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct kocsi
{
	char nev[25];
	int kor, ar;
};

class Kereskedes
{
public:
	int db;
	kocsi* kocsik;
	Kereskedes(char*);
	void kiir();
	double atlag();
	kocsi legfiatalabb();
	~Kereskedes();
};

int main()
{
	setlocale(LC_ALL, "hun");
	char fajlnev[] = "auto.dat";
	Kereskedes k(fajlnev);
	k.kiir();
	cout << "Az autók átlagos ára: " << setprecision(10) << k.atlag() << endl;
	kocsi legfiatalabb = k.legfiatalabb();
	cout << "A legfiatalabb autó adatai:" << endl;
	cout << "Név: " << legfiatalabb.nev << endl;
	cout << "Kor: " << legfiatalabb.kor << endl;
	cout << "Ár: " << legfiatalabb.ar << endl;

	return 0;
}

Kereskedes::Kereskedes(char* fajlnev)
{
	ifstream be(fajlnev, ios::binary);
	if (be.fail())
	{
		cout << "Hiba a fájl megnyitásakor!" << endl;
		exit(-1);
	}
	db = 0;
	kocsi K;
	while (!be.eof())
	{
		be.read((char*)&K, sizeof(K));
		if (!be.eof())
			db++;
	}
	be.clear();
	be.seekg(0, ios::beg);
	kocsik = new kocsi[db];
	for (int i = 0; i < db; i++)
	{
		be.read((char*)&kocsik[i], sizeof(kocsik[i]));
	}
	be.close();
}

void Kereskedes::kiir()
{
	cout << "Az autók száma: " << db << endl;
	cout << "Az autók adatai:" << endl;
	cout.setf(ios::left);
	cout << setw(25) << "Név" << setw(10) << "Kor" << setw(10) << "Ár" << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(25) << kocsik[i].nev << setw(10) << kocsik[i].kor << setw(10) << kocsik[i].ar << endl;
	}
}

double Kereskedes::atlag()
{
	double atlag = 0;
	for (int i = 0; i < db; i++)
	{
		atlag += kocsik[i].ar;
	}
	return atlag / db;
}

kocsi Kereskedes::legfiatalabb()
{
	kocsi legfiatalabb;
	legfiatalabb = kocsik[0];
	for (int i = 1; i < db; i++)
	{
		if (kocsik[i].kor > legfiatalabb.kor)
			legfiatalabb = kocsik[i];
	}

	return legfiatalabb;
}

Kereskedes::~Kereskedes()
{
	delete[] kocsik;
}