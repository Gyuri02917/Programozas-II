#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Tanulo {
    string nev;
    int felvettKredit;
    int teljesitettKredit;
    int jegyek[5];
    float atlag = 0.000;
};

Tanulo legjobb(Tanulo[], int);

int main()
{
    setlocale(LC_ALL, "UTF-8");
    Tanulo tanulok[5];
    ifstream be("tanulok.txt");
    if (be.fail()) {
        cerr << "Hiba a fájl megnyitásakor!" << endl;
        return 1;
    }
    
    string seged;
    int db = 0;
    while(getline(be, seged, ',')) {
        tanulok[db].nev = seged;
        be >> tanulok[db].felvettKredit;
        be.ignore();
        be >> tanulok[db].teljesitettKredit;
        be.ignore();
        for (int i = 0; i < 5; i++) {
            be >> tanulok[db].jegyek[i];
        }
        for (int i = 0; i < 5; i++) {
            tanulok[db].atlag += tanulok[db].jegyek[i];
        }
        tanulok[db].atlag /= 5;
        db++;
    }
    be.close();

    for(int i = 0; i<db;i++)
    {
        cout<<tanulok[i].nev<<endl;
        cout<<tanulok[i].felvettKredit<<endl;
        cout<<tanulok[i].teljesitettKredit<<endl;
        for(int j=0;j<5;j++)
        {
            cout<<tanulok[i].jegyek[j]<<" ";
        }
        cout<<endl;
        cout<<tanulok[i].atlag<<endl;
        cout<<endl<<endl;
    }

	Tanulo legjobb = legjobb(tanulok, db);
    cout << fixed;
	cout << "A legjobb tanulo: " << legjobb.nev << ", átlaga: " << setprecision(3) << legjobb.atlag << endl;

    return 0;
}

Tanulo legjobb(Tanulo tanulok[], int db)
{
	Tanulo legjobb;
	for (int i = 0; i < db;i++)
	{
		if (tanulok[i].atlag > legjobb.atlag)
		{
			legjobb = tanulok[i];
		}
	}
	return legjobb;
}