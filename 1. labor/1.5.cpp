#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "hun");
    string konyv;
    cout<<"Adja meg a kedvenc könyvének a szerzőjét, és a címét: ";
    getline(cin, konyv);
    cout << "A 4. karakter: " << konyv[3] << " az utolsó karakter: " << konyv[konyv.length()-1] << endl;
    cout << "A változó hossza: " << konyv.length() << endl;
    konyv.append(" - ez a kedvenc könyvem");
    if(konyv.find("egy") != -1)
    {
        cout << "A szöveg tartalmazza az 'egy' szót." << endl;
    }
    else
    {
        cout << "A szöveg nem tartalmazza az 'egy' szót." << endl;
    }

    string konyv2;
    konyv2 = konyv.substr(0, 10);
    konyv2.insert(0, "Másolat: ");

    cout << "Az eredeti string: " << konyv << endl;
    cout << "A másolat: " << konyv2 << endl;

    return 0;
}