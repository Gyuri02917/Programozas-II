#include <iostream>
#include <string>
using namespace std;

// Sz�l�oszt�ly: Egyetem
class Egyetem {
protected:
    string egyetemNeve;

public:
	Egyetem(string nev) : egyetemNeve(nev) {}
    void egyetemLekerdezes() {
        cout << "Egyetem neve: " << egyetemNeve << endl;
    }
};

// Gyermekoszt�ly: Kar
class Kar : public Egyetem {
protected:
    string karNeve;

public:
	Kar(string egyetemNeve, string karNeve) : Egyetem(egyetemNeve), karNeve(karNeve) {}
    void karLekerdezes() {
        egyetemLekerdezes();
        cout << "Kar neve: " << karNeve << endl;
    }
};

// Gyermekoszt�ly: Szak
class Szak : public Kar {
protected:
    string szakNeve;

public:
	Szak(string egyetemNeve, string karNeve, string szakNeve) : Kar(egyetemNeve, karNeve), szakNeve(szakNeve) {}
    void szakLekerdezes() {
        egyetemLekerdezes();
        cout << "Szak neve: " << szakNeve << endl;
    }
};

// Gyermekoszt�ly: �vfolyam
class Evfolyam : public Szak {
protected:
    int evfolyamEve;

public:
	Evfolyam(string egyetemNeve, string karNeve, string szakNeve, int evfolyamEve) : Szak(egyetemNeve, karNeve, szakNeve), evfolyamEve(evfolyamEve) {
	}
    void evfolyamLekerdezes() {
        szakLekerdezes();
        cout << "Evfolyam szama: " << evfolyamEve << endl;
    }
};

// Gyermekoszt�ly: Csoport
class Csoport : public Evfolyam {
protected:
    string csoportNeve;

public:
	Csoport(string egyetemNeve, string karNeve, string szakNeve, int evfolyamEve, string csoportNeve) : Evfolyam(egyetemNeve, karNeve, szakNeve, evfolyamEve), csoportNeve(csoportNeve) {
	}
    void csoportLekerdezes() {
        evfolyamLekerdezes();
        cout << "Csoport neve: " << csoportNeve << endl;
    }
};

// Gyermekoszt�ly: Hallgat�
class Hallgato : public Csoport {
private:
    string hallgatoNeve;

public:
	Hallgato(string egyetemNeve, string karNeve, string szakNeve, int evfolyamEve, string csoportNeve, string hallgatoNeve) : Csoport(egyetemNeve, karNeve, szakNeve, evfolyamEve, csoportNeve), hallgatoNeve(hallgatoNeve) {}
    void hallgatoLekerdez() {
        csoportLekerdezes();
        cout << "Hallgato neve: " << hallgatoNeve << endl;
    }
};

int main() {
    Hallgato hallgato("Neumann Janos Egyetem", "GAMF Kar", "Mernokinformatikus", 2024, "LA01", "Minta Milan");
    hallgato.hallgatoLekerdez(); // Hierarchia �sszes adat�nak megjelen�t�se

    return 0;
}
