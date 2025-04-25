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
	cout << "A csapat �sszes l�v�s�nek sz�ma: " << L.Osszesloves() << endl;
	jatekos golok = L.Legtobbgol();
	cout << "A legt�bb g�lt: " << golok.nev << " l�tte, aki " << golok.szul << "-ben sz�letett, " << golok.poszt << " poszton j�tszik, meccsei sz�ma: " << golok.meccs << ", l�v�seinek sz�ma: " << golok.loves << ", g�lok sz�ma: " << golok.gol << endl;
	L.Fiatalok();
	if (L.Egyforma())
		cout << "Volt egyforma g�lsz�m" << endl;
	else
		cout << "Nem volt egyforma g�lsz�m" << endl;

	return 0;
}

Labdarugo::Labdarugo(string fnev)
{
	ifstream be(fnev);
	if (be.fail())
	{
		cerr << "Hiba a f�jl megnyit�sakor!" << endl;
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
	cout << "Az 1995 ut�n sz�letett j�t�kosok: " << endl;
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