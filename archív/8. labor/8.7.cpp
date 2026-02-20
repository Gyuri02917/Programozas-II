#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Szemely {
protected:
    string nev;
    int azonosito;
public:
    Szemely(string nev, int azon);
    virtual void kiir() const;
    virtual ~Szemely() {} // Virtuális destruktor a polimorfizmus miatt
};

class Dolgozo : public Szemely {
private:
    string beosztas;
public:
    Dolgozo(string nev, int azon, string beosztas);
    void kiir() const override;
};

class Olvaso : public Szemely {
private:
    string* kolcsonzottKonyvek; // Dinamikus tömb
    int maxKonyvek;
    int konyvSzam;
public:
    Olvaso(string nev, int azon, int maxKonyvek);
    ~Olvaso();
    void kolcsonoz(string konyv);
    void visszavisz(string konyv);
    void kiir() const override;
};

class Konyv {
private:
	string szerzo;
	string cim;
    int ev;
    string kolcsonozte;
public:
	Konyv(string szerzo, string cim, int ev, string kolcsonozte);
	void kiir() const;
};

int main() {
    setlocale(LC_ALL, "hun");

    // Fájlok megnyitása
    ifstream beDolgozo("dolgozok.txt");
    ifstream beOlvaso("olvasok.txt");
    ifstream beKonyv("konyvek.txt");
    if (!beDolgozo) {
        cerr << "Hiba a dolgozok.txt megnyitásakor!" << endl;
        exit(-1);
    }
    if (!beOlvaso) {
        cerr << "Hiba az olvasok.txt megnyitásakor!" << endl;
        exit(-2);
    }
    if (!beKonyv) {
        cerr << "Hiba a konyvek.txt megnyitásakor!" << endl;
        exit(-3);
    }

    // Dolgozók feldolgozása
    string sor;
    int dbDolgozo = 0;
    while (getline(beDolgozo, sor)) {
        dbDolgozo++;
    }
    beDolgozo.clear();
    beDolgozo.seekg(0, ios::beg);

    Szemely** dolgozok = new Szemely * [dbDolgozo];
    for (int i = 0; i < dbDolgozo; i++) {
        string nev, beosztas;
        int azon;
        beDolgozo >> nev >> azon >> beosztas;
        dolgozok[i] = new Dolgozo(nev, azon, beosztas);
    }

    // Olvasók feldolgozása
    int dbOlvaso = 0;
    while (getline(beOlvaso, sor)) {
        dbOlvaso++;
    }
    beOlvaso.clear();
    beOlvaso.seekg(0, ios::beg);

    Szemely** olvasok = new Szemely * [dbOlvaso];
    for (int i = 0; i < dbOlvaso; i++) {
        string nev;
        int azon;

        // Beolvasás neve és azonosítója
        beOlvaso >> nev >> azon;

        // Dinamikus tömb létrehozása a könyvek tárolására
        int maxKonyvek = 10; // Állítsd be a maximális könyvek számát
        string* konyvek = new string[maxKonyvek];
        int konyvSzam = 0;

        string konyv;
        while (beOlvaso >> konyv) {
            // Ellenõrizzük, hogy a sor vége-e
            if (beOlvaso.peek() == '\n' || beOlvaso.eof()) {
                konyvek[konyvSzam++] = konyv;
                break;
            }
            konyvek[konyvSzam++] = konyv;

            // Ellenõrzés a maximális könyvszám túllépésére
            if (konyvSzam >= maxKonyvek) {
                cout << "Figyelmeztetés: az olvasó maximális könyvszámot kölcsönöz!" << endl;
                break;
            }
        }

        // Olvasó létrehozása
        Olvaso* olvaso = new Olvaso(nev, azon, maxKonyvek);

        // Könyvek hozzáadása az olvasóhoz
        for (int j = 0; j < konyvSzam; j++) {
            olvaso->kolcsonoz(konyvek[j]);
        }

        // Dinamikus tömb felszabadítása
        delete[] konyvek;

        olvasok[i] = olvaso;
    }

	// Könyvek feldolgozása
	int dbKonyv = 0;
	while (getline(beKonyv, sor)) {
		dbKonyv++;
	}
	beKonyv.clear();
	beKonyv.seekg(0, ios::beg);
	Konyv** konyvek = new Konyv*[dbKonyv];
	for (int i = 0; i < dbKonyv; i++) {
		string szerzo, cim, kolcsonozte;
		int ev;
		beKonyv >> cim >> szerzo >> ev >> kolcsonozte;
		konyvek[i] = new Konyv(szerzo, cim, ev, kolcsonozte);
	}
	beKonyv.close();

    // Dolgozók kiíratása
    cout << "Dolgozók adatai:\n";
    for (int i = 0; i < dbDolgozo; i++) {
        dolgozok[i]->kiir();
    }

    // Olvasók kiíratása
    cout << "\nOlvasók adatai:\n";
    for (int i = 0; i < dbOlvaso; i++) {
        olvasok[i]->kiir();
    }

	// Könyvek kiíratása
	cout << "\nKönyvek adatai:\n";
	for (int i = 0; i < dbKonyv; i++) {
		konyvek[i]->kiir();
	}

    // Memória felszabadítása
    for (int i = 0; i < dbDolgozo; i++) {
        delete dolgozok[i];
    }
    delete[] dolgozok;

    for (int i = 0; i < dbOlvaso; i++) {
        delete olvasok[i];
    }
    delete[] olvasok;

    return 0;
}

// Szemely osztály
Szemely::Szemely(string nev, int azon) {
    this->nev = nev;
    this->azonosito = azon;
}

void Szemely::kiir() const {
    cout << "Név: " << nev << ", Azonosító: " << azonosito;
}

// Dolgozo osztály
Dolgozo::Dolgozo(string nev, int azon, string beosztas) : Szemely(nev, azon) {
    this->beosztas = beosztas;
}

void Dolgozo::kiir() const {
    Szemely::kiir();
    cout << ", Beosztás: " << beosztas << endl;
}

// Olvaso osztály
Olvaso::Olvaso(string nev, int azon, int maxKonyvek) : Szemely(nev, azon) {
    this->maxKonyvek = maxKonyvek;
    this->konyvSzam = 0;
    kolcsonzottKonyvek = new string[maxKonyvek];
}

Olvaso::~Olvaso() {
    delete[] kolcsonzottKonyvek;
}

void Olvaso::kolcsonoz(string konyv) {
    if (konyvSzam < maxKonyvek) {
        kolcsonzottKonyvek[konyvSzam] = konyv;
        konyvSzam++;
    }
    else {
        cout << "Maximális könyvszám elérve!" << endl;
    }
}

void Olvaso::visszavisz(string konyv) {
    for (int i = 0; i < konyvSzam; i++) {
        if (kolcsonzottKonyvek[i] == konyv) {
            for (int j = i; j < konyvSzam - 1; j++) {
                kolcsonzottKonyvek[j] = kolcsonzottKonyvek[j + 1];
            }
            konyvSzam--;
            break;
        }
    }
}

void Olvaso::kiir() const {
    Szemely::kiir();
    cout << ", Kölcsönzött könyvek: ";
    for (int i = 0; i < konyvSzam; i++) {
        cout << kolcsonzottKonyvek[i];
        if (i < konyvSzam - 1) cout << ", ";
    }
    cout << endl;
}

Konyv::Konyv(string szerzo, string cim, int ev, string kolcsonozte) {
	this->szerzo = szerzo;
	this->cim = cim;
	this->ev = ev;
	this->kolcsonozte = kolcsonozte;
}

void Konyv::kiir() const {
	cout << "Szerzõ: " << szerzo << ", Cím: " << cim << ", Év: " << ev << ", Kölcsönözte: " << kolcsonozte << endl;
}