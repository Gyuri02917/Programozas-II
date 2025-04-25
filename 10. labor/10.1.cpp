#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct film {
	string nev;
	int evad, reszekszama, hossz, ar;
};

class Filmek
{
private:
	int db;
	film* tmb;
public:
	Filmek(string fnev);
	~Filmek();
	int Getadatdb();
	int Osszesreszszama();
	film Legdragabb();
	void Kiir();
};

int main()
{
	setlocale(LC_ALL, "hun");
	string fajlnev = "Filmsorozatok.txt";
	Filmek F(fajlnev);
	cout << "A sorozatok száma: " << F.Getadatdb() << endl;
	cout << "Az összes sorozat összes része: " << F.Osszesreszszama() << endl;
	film temp = F.Legdragabb();
	cout << "A legdrágább sorozat: " << temp.nev << ", évadok: " << temp.evad << ", részek: " << temp.reszekszama << ", ár: " << temp.ar << ", hossz: " << temp.hossz << endl;
	F.Kiir();

	return 0;
}

Filmek::Filmek(string fnev)
{
	db = 0;
	ifstream be(fnev);
	if (be.fail())
	{
		cerr << "Hiba a fájl megnyitásakor!" << endl;
		exit(-1);
	}
	string sor;
	while (getline(be, sor))
		db++;
	tmb = new film[db];
	be.clear();
	be.seekg(0, ios::beg);
	for (int i = 0;i < db;i++)
	{
		getline(be, tmb[i].nev, ';');
		getline(be, sor, ';');
		tmb[i].evad = stoi(sor);
		getline(be, sor, ';');
		tmb[i].reszekszama = stoi(sor);
		getline(be, sor, ';');
		tmb[i].hossz = stoi(sor);
		getline(be, sor);
		tmb[i].ar = stoi(sor);
	}
	be.close();
}

Filmek::~Filmek()
{
	delete[] tmb;
}

int Filmek::Getadatdb()
{
	return db;
}

int Filmek::Osszesreszszama()
{
	int ossz = 0;
	for (int i = 0;i < db;i++)
	{
		ossz += tmb[i].evad * tmb[i].reszekszama;
	}
	return ossz;
}

film Filmek::Legdragabb()
{
	int max = 0;
	for (int i = 1;i < db;i++)
	{
		if (tmb[i].ar > tmb[max].ar)
			max = i;
	}
	return tmb[max];
}

void Filmek::Kiir()
{
	cout.setf(ios::left);
	for (int i = 0;i < db;i++)
	{
		cout << i + 1 << ". " << setw(20) << tmb[i].nev << setw(5) << tmb[i].evad << setw(5) << tmb[i].reszekszama << setw(5) << tmb[i].hossz << setw(5) << tmb[i].ar << endl;
	}
}