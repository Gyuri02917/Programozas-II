#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UTF-8");
	cout << "*** Hagyományos (statikus) memóriakezelés ***" << endl;
	int jegy[5] = { 5, 4, 3 };
	cout << "int jegy[5] = { 5, 4, 3 }; tömb mérete: " << sizeof(jegy) << endl;
	//A sizeof() megadja a tömb méretét bájtban, azaz a tömb elemeinek számát megszorozza az elemek méretével.
	cout << "jegy[0]=" << jegy[0] << endl;
	cout << "jegy[2]=" << *(jegy + 2) << endl;
	//A jegy kezdőcímétől a 2. elem címéig lépünk, majd a címen lévő értéket kiírjuk.

	cout << "*** Dinamikus memóriakezelés ***" << endl;
	int* szam;
	szam = new int; //A memóriacím bekerül az iptr-be
	if (szam == NULL)
	{
		cerr << "Nem sikerült a memóriafoglalás!" << endl;
		return 1;
	}

	*szam = 20; //Értékadás a dinamikus változónak
	cout << "szam=" << *szam << endl;
	delete szam; //A dinamikus változó felszabadítása
	//Dinamikus tömb használata, a halomban kerül tárolásra

	int db;
	cout << "*** dinamikus tömb használata ***" << endl;
	cout << "A dinamikus tömb elemszáma: n = ";
	cin >> db;
	int* tmb = new int[db];
	if (tmb == NULL)
	{
		cerr << "Nem sikerült a memóriafoglalás!" << endl;
		return 2;
	}

	cout << "sizeof(tmb): a mutató mérete = " << sizeof(tmb) << endl; //Ez nem a tömb, hanem a mutató méretét adja meg
	*tmb = 15;
	tmb[3] = 10;
	cout << "tmb[0]=" << tmb[0] << endl;
	*(tmb + 1) = 20;
	cout << "tmb[1]=" << *(tmb + 1) << endl;
	delete[] tmb;
	//Dinamikus tömb felszabadításakor fontos a [] használata, mert a tömb összes elemét felszabadítja.

	//Döntsük el, van-e értelme a következő programrészletnek! Van.e benne hiba? A tömb most statikus!
	int tomb[5] = { 1, 2, 3, 4, 5 };
	int i = 3;
	cout << tomb[i] << endl;
	cout << i[tomb] << endl;
	cout << &tomb[i] << endl;
	cout << &i[tomb] << endl;
	cout << "tmb[3] =" << *(tmb + 3) << endl; //Itt már nem létezik, ugyanis felszabadítottuk a memóriát

	return 0;
}
