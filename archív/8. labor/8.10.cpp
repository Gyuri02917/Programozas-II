#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Idojaras {
private:
	struct idojarasAdat
	{
		string datum;
		int ora, homerseklet, paratartalom, csapadek;
	};
	idojarasAdat* idojarasok;
	int meresekSzama;
public:
	Idojaras(char*);
	~Idojaras();
	void kiir();
	string legeslegNap();
	void atlagHomerseklet();
	void rekordIdo();
};

int main()
{
	setlocale(LC_ALL, "hun");
	char fajlNev[] = "idojaras.txt";
	Idojaras i(fajlNev);
	i.kiir();
	cout << "A legmelegebb idõ " << i.legeslegNap() << " napon volt." << endl;
	i.atlagHomerseklet();
	i.rekordIdo();
	
	return 0;
}

Idojaras::Idojaras(char* fajlnev)
{
	ifstream be(fajlnev);
	if (be.fail())
	{
		cerr << "Hiba a fájl megnyitásakor!" << endl;
		exit(-1);
	}
	string sor;
	int db = 0;
	while (getline(be, sor))
		db++;
	meresekSzama = db;
	be.clear();
	be.seekg(0, ios::beg);
	idojarasok = new idojarasAdat[meresekSzama];
	for (int i = 0; i < meresekSzama; i++)
	{
		be >> idojarasok[i].datum >> idojarasok[i].ora >> idojarasok[i].homerseklet >> idojarasok[i].paratartalom >> idojarasok[i].csapadek;
	}
	be.close();
}

Idojaras::~Idojaras()
{
	delete[] idojarasok;
}

void Idojaras::kiir()
{
	cout.setf(ios::left);
	cout << "A tárolt idõjárási adatok:" << endl;
	cout << setw(12) << "Dátum" << setw(4) << "Óra" << setw(4) << "Hõm" << setw(4) << "Pár" << setw(4) << "Csa" << endl;
	for (int i = 0;i < meresekSzama;i++)
	{
		cout << setw(12) << idojarasok[i].datum << setw(4) << idojarasok[i].ora << setw(4) << idojarasok[i].homerseklet << setw(4) << idojarasok[i].paratartalom << setw(4) << idojarasok[i].csapadek << endl;
	}
}

string Idojaras::legeslegNap()
{
	string adatok;
	int maxHom = idojarasok[0].homerseklet;
	
	for (int i = 0;i < meresekSzama; i++)
	{
		int index = i / 6;
		if (maxHom < idojarasok[i].homerseklet)
		{
			maxHom = idojarasok[i].homerseklet;
			adatok = idojarasok[i].datum;
		}
	}

	return adatok;
}

void Idojaras::atlagHomerseklet()
{
	cout << fixed;
	string* datumok = new string[meresekSzama / 6];
	double* atlagho = new double[meresekSzama / 6];
	for (int i = 0;i < meresekSzama / 6; i++)
	{
		atlagho[i] = 0;
	}
	for (int i = 0;i < meresekSzama; i++)
	{
		int index = i / 6;
		datumok[index] = idojarasok[i].datum;
		atlagho[index] += idojarasok[i].homerseklet;
	}
	for (int i = 0;i < meresekSzama / 6; i++)
	{
		atlagho[i] /= meresekSzama / 6;
		cout << datumok[i] << " napon " << setprecision(2) << atlagho[i] << " °C volt az átlaghõmérséklet" << endl;
	}
}

void Idojaras::rekordIdo()
{
	int minHom, maxHom;
	minHom = idojarasok[0].homerseklet;
	maxHom = idojarasok[0].homerseklet;

	for (int i = 1;i < meresekSzama; i++)
	{
		if (minHom > idojarasok[i].homerseklet)
			minHom = idojarasok[i].homerseklet;
		if (maxHom < idojarasok[i].homerseklet)
			maxHom = idojarasok[i].homerseklet;
	}

	cout << "A legmelegebb hõmérséklet: " << maxHom << endl;
	cout << "A legalacsonyabb hõmérséklet: " << minHom << endl;
}