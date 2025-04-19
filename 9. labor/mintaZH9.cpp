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
	cout << "A f�jlban t�rolt hibak�dok sz�ma: " << hk.GetHibakodDb() << " db." << endl;
	cout << "A leghosszabb le�r�s:" << endl << "\t" << hk.LeghosszabLeiras() << endl;
	cout << "Adja meg a keresett hibak�dot: ";
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
		cerr << "Hiba a f�jl megnyit�sakor!" << endl;
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
		//Vari�ci� A
		be >> hiba[i].azonosito;
		be.get();
		getline(be, hiba[i].leiras);

		//Vari�ci� B
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
	cout << "A keresett hibak�d azonos�t�ja: " << hibakod << ", le�r�sa:\n" << hiba[ix].leiras << endl;
}

void Hibakodok::Kiir()
{
	cout.setf(ios::left);
	cout << setw(6) << "Hiba" << "Le�r�s" << endl;
	for (int i = 0;i < db;i++)
	{
		cout << setw(6) << hiba[i].azonosito << hiba[i].leiras << endl;
	}
}