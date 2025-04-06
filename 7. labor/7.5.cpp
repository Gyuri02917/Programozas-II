#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct kolcsonzes {
	string datum, tipus;
	int sorszam, ido;
};

class Kolcsonzo {
private:
	kolcsonzes* kolcsonzesek;
	int db;
public:
	Kolcsonzo(char*);
	~Kolcsonzo();
	int Getdb();
	int GetMagellan();
	int GetMedian();
	int MedianBevetel();
	int OsszBevetel();
	kolcsonzes LeghosszabbKolcsonzes();
	void Kiir();
};

const int medianAr = 1000;
const int magellanAr = 1200;

int main()
{
	setlocale(LC_ALL, "hun");
	char fajlnev[] = "kolcsonzo.txt";
	Kolcsonzo k(fajlnev);
	cout << "K�lcs�nz�sek sz�ma: " << k.Getdb() << endl;
	cout << "Magellan k�lcs�nz�sek sz�ma: " << k.GetMagellan() << endl;
	cout << "Median k�lcs�nz�sek sz�ma: " << k.GetMedian() << endl;
	cout << "Median bev�tele: " << k.MedianBevetel() << " Ft" << endl;
	cout << "�sszbev�tel: " << k.OsszBevetel() << " Ft" << endl;
	kolcsonzes max = k.LeghosszabbKolcsonzes();
	cout << "Leghosszabb k�lcs�nz�s: " << max.sorszam << " " << max.datum << " " << max.tipus << " " << max.ido << " nap" << endl;
	k.Kiir();

	return 0;
}

Kolcsonzo::Kolcsonzo(char* fajlnev) {
	ifstream be(fajlnev);
	if (be.fail()) {
		cerr << "Hiba a f�jl megnyit�sakor!" << endl;
		exit(-1);
	}
	be >> db;
	kolcsonzesek = new kolcsonzes[db];
	for (int i = 0; i < db; i++) {
		be >> kolcsonzesek[i].datum >> kolcsonzesek[i].tipus >> kolcsonzesek[i].ido;
		kolcsonzesek[i].sorszam = i + 1;
	}
	be.close();
}

Kolcsonzo::~Kolcsonzo() {
	delete[] kolcsonzesek;
}

int Kolcsonzo::Getdb() {
	return db;
}

int Kolcsonzo::GetMagellan() {
	int db = 0;
	for (int i = 0; i < this->db; i++) {
		if (kolcsonzesek[i].tipus == "Magellan") {
			db++;
		}
	}
	return db;
}

int Kolcsonzo::GetMedian() {
	int db = 0;
	for (int i = 0; i < this->db; i++) {
		if (kolcsonzesek[i].tipus == "Median") {
			db++;
		}
	}
	return db;
}

int Kolcsonzo::MedianBevetel() {
	int bevetel = 0;
	for (int i = 0; i < this->db; i++) {
		if (kolcsonzesek[i].tipus == "Median") {
			bevetel += kolcsonzesek[i].ido * medianAr;
		}
	}
	return bevetel;
}

int Kolcsonzo::OsszBevetel() {
	int bevetel = 0;
	for (int i = 0; i < this->db; i++) {
		if (kolcsonzesek[i].tipus == "Magellan") {
			bevetel += kolcsonzesek[i].ido * magellanAr;
		}
		else if (kolcsonzesek[i].tipus == "Median") {
			bevetel += kolcsonzesek[i].ido * medianAr;
		}
	}
	return bevetel;
}

kolcsonzes Kolcsonzo::LeghosszabbKolcsonzes() {
	kolcsonzes max = kolcsonzesek[0];
	for (int i = 1; i < db; i++) {
		if (kolcsonzesek[i].ido > max.ido) {
			max = kolcsonzesek[i];
		}
	}
	return max;
}

void Kolcsonzo::Kiir() {
	cout.setf(ios::left);
	cout << "A k�lcs�nz�sek adatai:" << endl;
	cout << setw(5) << "Ssz" << setw(12) << "D�tum" << setw(10) << "T�pus" << setw(5) << "Id�" << endl;
	for (int i = 0; i < db; i++) {
		cout << setw(5) << kolcsonzesek[i].sorszam << setw(12) << kolcsonzesek[i].datum << setw(10) << kolcsonzesek[i].tipus << setw(5) << kolcsonzesek[i].ido << endl;
	}
}