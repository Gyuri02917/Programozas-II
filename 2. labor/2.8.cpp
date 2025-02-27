#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	setlocale(LC_ALL, "UTF-8");
	vector<int> jegyek(3);
	char betu;
	int szam = 0;

	//Az első három jegy bekérése
	for (int i = 0; i < 3; i++)
	{
		cout << "Kérem adja meg a(z) " << i + 1 << ". jegyet: ";
		cin >> jegyek[i];
	}

	cout << "Szeretne még jegyet rögzíteni? (I/N): ";
	cin >> betu;
	betu = toupper(betu); //Nagybetűssé konvertálás
	if (betu == 'I')
	{
		do
		{
			cout << "Kérem adja meg a következő jegyet: ";
			cin >> szam;
			jegyek.push_back(szam); //A jegy hozzáadása a vektorhoz
			cout << "Szeretne még jegyet rögzíteni? (I/N): ";
			cin >> betu;
			betu = toupper(betu); //Nagybetűssé konvertálás
		} while (betu == 'I');
	}

	//A jegyek száma
	cout << "A rögzített jegyek száma: " << jegyek.size() << endl;
	for (int i = 0; i < jegyek.size(); i++)
	{
		cout << "A(z) " << i + 1 << ". jegy: " << jegyek[i] << endl;
		cout << "Ugyanaz másképpen: " << jegyek.at(i) << endl;
	}

	//Az utolsó jegy törlése
	jegyek.pop_back();
	cout << "Az aktuális jegyek a törlés után: " << endl;
	for (int i = 0; i < jegyek.size(); i++)
	{
		cout << "A(z) " << i + 1 << ". jegy: " << jegyek[i] << endl;
	}

	return 0;
}
