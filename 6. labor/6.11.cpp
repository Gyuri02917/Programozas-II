#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct olimpia
{
	int hely, versenyszam;
	string sportag, versenynev;
};

class Helsinki
{
private:
	olimpia* adatok;
	int db;
public:
	Helsinki(const char* fajlnev);
	~Helsinki();
	void kiir();
	int elsokszama();
	string legtobbsportag();
	void ermesuszok();
};

int main()
{
	setlocale(LC_ALL, "hun");
	char fajlnev[] = "helsinki.txt";
	Helsinki h(fajlnev);
	h.kiir();
	cout << "Az első helyezések száma: " << h.elsokszama() << endl;
	cout << "A legtöbb sportágban versenyzők száma: " << h.legtobbsportag() << endl;
	cout << "Úszó versenyszámok legjobb eredményei: " << endl;
	h.ermesuszok();

	return 0;
}

Helsinki::Helsinki(const char* fajlnev)
{
	ifstream be(fajlnev);
	if (be.fail())
	{
		cerr << "Hiba a fájl megnyitásakor!" << endl;
		exit(-1);
	}
	int i = 0;
	string sor;
	while (getline(be, sor))
	{
		i++;
	}
	db = i;
	adatok = new olimpia[db];
	be.clear();
	be.seekg(0, ios::beg);
	for (int i = 0; i < db; i++)
	{
		be >> adatok[i].hely >> adatok[i].versenyszam >> adatok[i].sportag >> adatok[i].versenynev;
	}
	be.close();
}

Helsinki::~Helsinki()
{
	delete[] adatok;
}

void Helsinki::kiir()
{
	cout << "A helyezést elért versenyzők száma: " << db << endl;
	cout.setf(ios::left);
	cout << setw(5) << "Hely" << setw(5) << "Vsz" << setw(20) << "Sportág" << setw(30) << "Versenynév" << endl;
	for (int i = 0; i < db; i++)
	{
		cout << setw(5) << adatok[i].hely << setw(5) << adatok[i].versenyszam << setw(20) << adatok[i].sportag << setw(30) << adatok[i].versenynev << endl;
	}
}

int Helsinki::elsokszama()
{
	int elsok = 0;
	for (int i = 0; i < db; i++)
	{
		if (adatok[i].hely == 1)
		{
			elsok++;
		}
	}
	return elsok;
}

string Helsinki::legtobbsportag()
{
	int max = 0;
	for (int i = 0; i < db; i++)
	{
		if (adatok[i].versenyszam < adatok[max].versenyszam)
		{
			max = i;
		}
	}
	return adatok[max].sportag;
}

void Helsinki::ermesuszok()
{
	cout.setf(ios::left);
	for (int i = 0; i < db; i++)
	{
		if (adatok[i].hely < 4 && adatok[i].sportag == "uszas")
		{
			cout << setw(30) << adatok[i].versenynev << " " << adatok[i].hely << endl;
		}
	}
}