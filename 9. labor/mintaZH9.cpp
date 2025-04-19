#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Hibakodok
{
private:
	struct hibak
	{
		string azonosito;
		string leiras;
	};
	hibak* hiba;
	int db;
public:
	Hibakodok(char*);
	~Hibakodok();
	int GetHibakodDb();
	string LeghosszabLeiras();
	void KeresesHibakodAlapjan(string);
	void Kiir();
};

int main()
{
	setlocale(LC_ALL, "hun");
	char fajl[] = "OBDHibakodok.txt";
	Hibakodok hk(fajl);
	hk.Kiir();
	cout << "A féjlban tárolt hibakódok száma: " << hk.GetHibakodDb() << " db." << endl;
	cout << "A leghosszabb leírás:" << endl << "\t" << hk.LeghosszabLeiras() << endl;
	cout << "Adja meg a keresett hibakódot: ";
	string hibakod;
	cin >> hibakod;
	hk.KeresesHibakodAlapjan(hibakod);

	return 0;
}

Hibakodok::Hibakodok(char* fajlnev)
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
	this->db = db;
	hiba = new hibak[this->db];
	be.clear();
	be.seekg(0, ios::beg);
	for (int i = 0;i < this->db;i++)
	{
		//Variáció A
		be >> hiba[i].azonosito;
		be.get();
		getline(be, hiba[i].leiras);

		//Variáció B
		//getline(be, hiba[i].azonosito, ' ');
		//getline(be, hiba[i].leiras);
	}
	be.close();
}

Hibakodok::~Hibakodok()
{
	delete[] hiba;
}

int Hibakodok::GetHibakodDb()
{
	return db;
}

string Hibakodok::LeghosszabLeiras()
{
	int hossz = hiba[0].leiras.length();
	int ix;
	for (int i = 1;i < db;i++)
	{
		if (hossz < hiba[i].leiras.length())
		{
			hossz = hiba[i].leiras.length();
			ix = i;
		}
	}
	return hiba[ix].leiras;
}

void Hibakodok::KeresesHibakodAlapjan(string hibakod)
{
	int ix;
	for (int i = 0;i < db;i++)
	{
		if (hibakod == hiba[i].azonosito)
		{
			ix = i;
			break;
		}
	}
	cout << "A keresett hibakód azonosítója: " << hibakod << ", leírása:\n" << hiba[ix].leiras << endl;
}

void Hibakodok::Kiir()
{
	cout.setf(ios::left);
	cout << setw(6) << "Hiba" << "Leírás" << endl;
	for (int i = 0;i < db;i++)
	{
		cout << setw(6) << hiba[i].azonosito << hiba[i].leiras << endl;
	}
}