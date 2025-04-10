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
    virtual ~Szemely() {} // Virtu�lis destruktor a polimorfizmus miatt
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
    string* kolcsonzottKonyvek; // Dinamikus t�mb
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

    // F�jlok megnyit�sa
    ifstream beDolgozo("dolgozok.txt");
    ifstream beOlvaso("olvasok.txt");
    ifstream beKonyv("konyvek.txt");
    if (!beDolgozo) {
        cerr << "Hiba a dolgozok.txt megnyit�sakor!" << endl;
        exit(-1);
    }
    if (!beOlvaso) {
        cerr << "Hiba az olvasok.txt megnyit�sakor!" << endl;
        exit(-2);
    }
    if (!beKonyv) {
        cerr << "Hiba a konyvek.txt megnyit�sakor!" << endl;
        exit(-3);
    }

    // Dolgoz�k feldolgoz�sa
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

    // Olvas�k feldolgoz�sa
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

        // Beolvas�s neve �s azonos�t�ja
        beOlvaso >> nev >> azon;

        // Dinamikus t�mb l�trehoz�sa a k�nyvek t�rol�s�ra
        int maxKonyvek = 10; // �ll�tsd be a maxim�lis k�nyvek sz�m�t
        string* konyvek = new string[maxKonyvek];
        int konyvSzam = 0;

        string konyv;
        while (beOlvaso >> konyv) {
            // Ellen�rizz�k, hogy a sor v�ge-e
            if (beOlvaso.peek() == '\n' || beOlvaso.eof()) {
                konyvek[konyvSzam++] = konyv;
                break;
            }
            konyvek[konyvSzam++] = konyv;

            // Ellen�rz�s a maxim�lis k�nyvsz�m t�ll�p�s�re
            if (konyvSzam >= maxKonyvek) {
                cout << "Figyelmeztet�s: az olvas� maxim�lis k�nyvsz�mot k�lcs�n�z!" << endl;
                break;
            }
        }

        // Olvas� l�trehoz�sa
        Olvaso* olvaso = new Olvaso(nev, azon, maxKonyvek);

        // K�nyvek hozz�ad�sa az olvas�hoz
        for (int j = 0; j < konyvSzam; j++) {
            olvaso->kolcsonoz(konyvek[j]);
        }

        // Dinamikus t�mb felszabad�t�sa
        delete[] konyvek;

        olvasok[i] = olvaso;
    }

	// K�nyvek feldolgoz�sa
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

    // Dolgoz�k ki�rat�sa
    cout << "Dolgoz�k adatai:\n";
    for (int i = 0; i < dbDolgozo; i++) {
        dolgozok[i]->kiir();
    }

    // Olvas�k ki�rat�sa
    cout << "\nOlvas�k adatai:\n";
    for (int i = 0; i < dbOlvaso; i++) {
        olvasok[i]->kiir();
    }

	// K�nyvek ki�rat�sa
	cout << "\nK�nyvek adatai:\n";
	for (int i = 0; i < dbKonyv; i++) {
		konyvek[i]->kiir();
	}

    // Mem�ria felszabad�t�sa
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

// Szemely oszt�ly
Szemely::Szemely(string nev, int azon) {
    this->nev = nev;
    this->azonosito = azon;
}

void Szemely::kiir() const {
    cout << "N�v: " << nev << ", Azonos�t�: " << azonosito;
}

// Dolgozo oszt�ly
Dolgozo::Dolgozo(string nev, int azon, string beosztas) : Szemely(nev, azon) {
    this->beosztas = beosztas;
}

void Dolgozo::kiir() const {
    Szemely::kiir();
    cout << ", Beoszt�s: " << beosztas << endl;
}

// Olvaso oszt�ly
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
        cout << "Maxim�lis k�nyvsz�m el�rve!" << endl;
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
    cout << ", K�lcs�nz�tt k�nyvek: ";
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
	cout << "Szerz�: " << szerzo << ", C�m: " << cim << ", �v: " << ev << ", K�lcs�n�zte: " << kolcsonozte << endl;
}