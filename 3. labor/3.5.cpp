#include <iostream>
using namespace std;

double Atlag(int*, int);

int main()
{
	setlocale(LC_ALL, "UTF-8");
	int jegy[10] = { 5, 4, 3, 5, 2, 3, 4, 5, 1, 2 };
	int pont[10] = { 86, 76, 73, 90, 50, 63, 84, 87, 5, 52 };

	cout << "A számtani átlaga a jegyeknek: " << Atlag(jegy, 10) << endl;
	cout << "A számtani átlaga a pontoknak: " << Atlag(pont, sizeof(pont) / sizeof(pont[0])) << endl;
	//sizeof(pont) --> 40 byte
	//sizeof(pont[0]) --> 4 byte
	//sizeof(pont) / sizeof(pont[0]) --> 10 elem

	return 0;
}
double Atlag(int* tmb, int db)
{
	double osszeg = 0;
	for (int i = 0; i < db; i++)
	{
		osszeg += tmb[i];
	}
	return osszeg / db;
}