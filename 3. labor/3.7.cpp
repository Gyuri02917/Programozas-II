#include <iostream>
using namespace std;

void csere(int x, int y);

int main()
{
	setlocale(LC_ALL, "UTF-8");
	int szam1, szam2;
	cout << "Adja meg az első számot: ";
	cin >> szam1;
	cin.ignore();
	cout << "Adja meg a második számot: ";
	cin >> szam2;
	cin.ignore();
	cout << "Az első szám: " << szam1 << ", a második szám: " << szam2 << endl;
	csere(szam1, szam2); //fgv hiváskor adjuk át a szam1, szam2 értékeit
	cout << "Az első szám: " << szam1 << ", a második szám: " << szam2 << endl;

	return 0;
}

void csere(int x, int y) //érték szerinti paraméterátadás
{
	int seged = x;
	x = y;
	y = seged;
}