#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

struct Versenyzok
{
    string nev;
    int rajtszam, szakitas, lokes, suly;
};

int main()
{
    setlocale(LC_ALL, "UTF-8");
    Versenyzok versenyzo[15];
    srand((unsigned)time(NULL));
    ifstream be("nevek.txt");
    if(be.fail())
    {
        cout << "Hiba a fájl megnyitásakor!" << endl;
        return 1;
    }

    int db = 0;
    while(be>>versenyzo[db].szakitas >> versenyzo[db].lokes)
    {
        getline(be, versenyzo[db].nev);
        versenyzo[db].rajtszam = rand() % 90 + 10;
        do {
            cout<<"Adja meg a " << versenyzo[db].nev << " nevű versenyző súlyát: ";
            cin >> versenyzo[db].suly;
            if(cin.fail())
            {
                cin.clear();
            }
            cin.ignore();
        } while(versenyzo[db].suly < 95 || versenyzo[db].suly > 150);
        db++;
    }

    be.close();

    cout.setf(ios::left);
    cout << setw(4) << "Rsz" << setw(20) << "Név" << setw(5) << "Súly" << setw(5) << "Sz" << setw(5) << "L" << setw(5) << "Össz" << endl;
    for(int i = 0; i< db; i++)
    {
        cout << setw(4) << versenyzo[i].rajtszam << setw(20) << versenyzo[i].nev << setw(5) << versenyzo[i].suly << setw(5) << versenyzo[i].szakitas << setw(5) << versenyzo[i].lokes << setw(5) << versenyzo[i].lokes + versenyzo[i].szakitas << endl;
    }

    int tobbmint400 = 0;
    int tobbmint100 = 0;
    for (int i = 0; i < db; i++)
    {
        if(versenyzo[i].lokes + versenyzo[i].szakitas > 400)
        {
            tobbmint400++;
        }
        if(versenyzo[i].suly < 100)
        {
            tobbmint100++;
        }
    }

    cout << "400 kg-nál többet emelt: " << tobbmint400 << " fő." << endl;
    cout << "100 kg-nál kisebb súlyú versenyzők száma: " << tobbmint100 << " fő." << endl;
    cout<<"Az utolsó nevező adatai: " << versenyzo[db-1].rajtszam << " " << versenyzo[db-1].nev << endl;
    
    ofstream ki("eredmeny.txt");
    if(ki.fail())
    {
        cout << "Hiba a fájl megnyitásakor!" << endl;
        return 2;
    }

    for(int i = 0; i < db; i++)
    {
        ki << versenyzo[i].rajtszam << " " << versenyzo[i].nev << " " << versenyzo[i].suly << " " << versenyzo[i].szakitas << " " << versenyzo[i].lokes << endl;
    }

    ki.close();

    return 0;
}