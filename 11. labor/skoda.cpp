#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Auto
{
	int CarID;
	string Model;
	int Year;
	int Price;
	string FuelType;
	bool IsElectric;
};

class MladaBoleslav
{
private:
	Auto* adatok;
	int adatokSzama;
public:
	MladaBoleslav(char* fajl);
	~MladaBoleslav();
	void Kiir(int db = -1);
	Auto NewestCar();
	int ElectricCarCount();
	bool SearchByModel(string);
	double AvgPrice();
	int AboveAvgPriceCars(double);
};

int main()
{
	char fajlnev[] = "Škoda.txt";
	MladaBoleslav CZ(fajlnev);
	CZ.Kiir();
	Auto temp = CZ.NewestCar();
	cout << "\nA legfiatalabb auto a(z) " << temp.Model << ", " << temp.Year << " evjarattal." << endl;
	cout << CZ.ElectricCarCount() << " db elektromos/hibrid auto van a listaban!" << endl;
	cout << "Adja meg a keresett auto nevet: ";
	string sor;
	getline(cin, sor);
	if (CZ.SearchByModel(sor))
		cout << "A keresett auto: " << sor << ", megtalalhato a listaban!" << endl;
	else
		cout << "A keresett auto: " << sor << ", nem talalhato meg a listaban!" << endl;
	cout << "Az autok atlagara: " << setprecision(12) << CZ.AvgPrice() << endl;
	cout << "Az atlagar feletti autok szama: " << CZ.AboveAvgPriceCars(CZ.AvgPrice()) << endl;

	return 0;
}

MladaBoleslav::MladaBoleslav(char* fajl)
{
	ifstream be(fajl);
	if (be.fail())
	{
		cerr << "Hiba a fajl megnyitasakor!" << endl;
		exit(-1);
	}
	string sor;
	adatokSzama = 0;
	getline(be, sor);
	while (getline(be, sor))
		adatokSzama++;
	adatok = new Auto[adatokSzama];
	be.clear();
	be.seekg(0, ios::beg);
	getline(be, sor);
	for (int i = 0;i < adatokSzama;i++)
	{
		getline(be, sor, ',');
		adatok[i].CarID = stoi(sor);
		getline(be, adatok[i].Model, ',');
		getline(be, sor, ',');
		adatok[i].Year = stoi(sor);
		getline(be, sor, ',');
		adatok[i].Price = stoi(sor);
		getline(be, sor, ',');
		adatok[i].FuelType = sor;
		getline(be, sor);
		adatok[i].IsElectric = stoi(sor);
	}
	be.close();
}

MladaBoleslav::~MladaBoleslav()
{
	delete[] adatok;
}

void MladaBoleslav::Kiir(int db)
{
	if (db == -1)
		db = adatokSzama;
	cout.setf(ios::left);
	cout << setw(5) << "ID" << setw(40) << "Model" << setw(5) << "Year" << setw(10) << "Price" << setw(20) << "Fuel" << setw(20) << "Electric?" << endl;
	for (int i = 0;i < db; i++)
	{
		cout << setw(5) << adatok[i].CarID << setw(40) << adatok[i].Model << setw(5) << adatok[i].Year << setw(10) << adatok[i].Price << setw(20) << adatok[i].FuelType;
		if (adatok[i].IsElectric)
			cout << setw(20) << "Electric/Hibrid" << endl;
		else
			cout << setw(12) << "" << endl;
	}
}

Auto MladaBoleslav::NewestCar()
{
	Auto temp = adatok[0];
	for (int i = 0; i < adatokSzama; i++)
	{
		if (adatok[i].Year > temp.Year)
			temp = adatok[i];
	}
	return temp;
}

int MladaBoleslav::ElectricCarCount()
{
	int db = 0;
	for (int i = 0;i < adatokSzama;i++)
	{
		if (adatok[i].IsElectric)
			db++;
	}
	return db;
}

bool MladaBoleslav::SearchByModel(string adat)
{
	for (int i = 0;i < adatokSzama;i++)
	{
		if (adat == adatok[i].Model)
			return true;
	}
	return false;
}

double MladaBoleslav::AvgPrice()
{
	double ar = 0;
	for (int i = 0;i < adatokSzama;i++)
	{
		ar += adatok[i].Price;
	}
	return ar / adatokSzama;
}

int MladaBoleslav::AboveAvgPriceCars(double ar)
{
	int db = 0;
	for (int i = 0;i < adatokSzama;i++)
	{
		if (ar < adatok[i].Price)
			db++;
	}
	return db;
}