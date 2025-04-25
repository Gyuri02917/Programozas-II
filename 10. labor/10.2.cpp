#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct jatekos
{
	string nev, poszt;
	int szul, meccs, loves, gol;
};

class Labdarugo
{
private:
	int db;
	jatekos* tmb;
public:
	Labdarugo(string fnev);
	~Labdarugo();
	void Kiir();
	int GET_ADATDB();
	int Osszesloves();
	jatekos Legtobbgol();
	void Fiatalok();
	bool Egyforma();
};

int main()
{
	setlocale(LC_ALL, "hun");
	string fajlnev = "jatekosok.txt";
	Labdarugo L(fajlnev);
	cout << "A beolvasott adatok: " << endl;
	L.Kiir();
	cout << "A csapat összes lövésének száma: " << L.Osszesloves() << endl;
	jatekos golok = L.Legtobbgol();
	cout << "A legtöbb gólt: " << golok.nev << " lõtte, aki " << golok.szul << "-ben született, " << golok.poszt << " poszton játszik, meccsei száma: " << golok.meccs << ", lövéseinek száma: " << golok.loves << ", gólok száma: " << golok.gol << endl;
	L.Fiatalok();
	if (L.Egyforma())
		cout << "Volt egyforma gólszám" << endl;
	else
		cout << "Nem volt egyforma gólszám" << endl;

	return 0;
}

Labdarugo::Labdarugo(string fnev)
{
	ifstream be(fnev);
	if (be.fail())
	{
		cerr << "Hiba a fájl megnyitásakor!" << endl;
		exit(-1);
	}
	be >> db;
	be.get();
	tmb = new jatekos[db];
	string sor;
	for (int i = 0;i < db;i++)
	{
		getline(be, tmb[i].nev, ':');
		getline(be, sor, ':');
		tmb[i].szul = stoi(sor);
		getline(be, tmb[i].poszt, ':');
		getline(be, sor, ':');
		tmb[i].meccs = stoi(sor);
		getline(be, sor, ':');
		tmb[i].loves = stoi(sor);
		getline(be, sor);
		tmb[i].gol = stoi(sor);
	}
	be.close();
}

Labdarugo::~Labdarugo()
{
	delete[] tmb;
}

void Labdarugo::Kiir()
{
	cout.setf(ios::left);
	for (int i = 0;i < db;i++)
	{
		cout << i + 1 << ". " << setw(8) << tmb[i].nev << setw(8) << tmb[i].szul << setw(8) << tmb[i].poszt << setw(8) << tmb[i].meccs << setw(8) << tmb[i].loves << setw(8) << tmb[i].gol << endl;
	}
}

int Labdarugo::GET_ADATDB()
{
	return db;
}

int Labdarugo::Osszesloves()
{
	int ossz = 0;
	for (int i = 0;i < db;i++)
	{
		ossz += tmb[i].loves;
	}
	return ossz;
}

jatekos Labdarugo::Legtobbgol()
{
	int max = 0;
	for (int i = 0;i < db;i++)
	{
		if (tmb[i].gol > tmb[max].gol)
			max = i;
	}
	return tmb[max];
}

void Labdarugo::Fiatalok()
{
	cout << "Az 1995 után született játékosok: " << endl;
	for (int i = 0;i < db;i++)
	{
		if (tmb[i].szul >= 1995)
			cout << tmb[i].nev << " " << tmb[i].szul << " " << tmb[i].poszt << " " << tmb[i].meccs << " " << tmb[i].loves << " " << tmb[i].gol << " " << endl;
	}
}

bool Labdarugo::Egyforma()
{
	for (int i = 0;i < db;i++)
	{
		for (int j = i + 1;j < db;j++)
		{
			if (tmb[i].gol == tmb[j].gol)
				return true;
		}
	}
	return false;
}