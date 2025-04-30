#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Game
{
	int GameID;
	string Name;
	float ReviewScore;
	int ReviewCount;
	float Price;
	bool Discounted;
};

class SteamStore
{
private:
	Game* adatok;
	int adatokSzama;
public:
	SteamStore(char* fajl);
	~SteamStore();
	void Kiir(int db = -1);
	Game MostReviewedGame();
	int DiscountedGamesCount();
	bool SearchByName(string);
	double AvgPrice();
	int AboveAvgPriceGames(double);
};

int main()
{
	char fajlnev[] = "SteamStore.log";
	SteamStore ss(fajlnev);
	ss.Kiir();
	Game temp = ss.MostReviewedGame();
	cout << "\nA legjobb ertekelest a(z) " << temp.Name << " jatek kapta, " << temp.ReviewScore << " ertekelessel." << endl;
	cout << ss.DiscountedGamesCount() << " db jatek van leertekelve!" << endl;
	cout << "Adja meg a keresett jatek nevet: ";
	string sor;
	getline(cin, sor);
	if (ss.SearchByName(sor))
		cout << "A keresett jatek: " << sor << ", megtalalhato a listaban!" << endl;
	else
		cout << "A keresett jatek: " << sor << ", nem talalhato meg a listaban!" << endl;
	cout << "A jatekok atlagara: " <<setprecision(4)<< ss.AvgPrice() << endl;
	cout << "Az atlagar feletti jatekok szama: " << ss.AboveAvgPriceGames(ss.AvgPrice()) << endl;

	return 0;
}

SteamStore::SteamStore(char* fajl)
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
	adatok = new Game[adatokSzama];
	be.clear();
	be.seekg(0, ios::beg);
	getline(be, sor);
	for (int i = 0;i < adatokSzama;i++)
	{
		getline(be, sor, ',');
		adatok[i].GameID = stoi(sor);
		getline(be, adatok[i].Name, ',');
		getline(be, sor, ',');
		adatok[i].ReviewScore = stof(sor);
  		getline(be, sor, ',');
		adatok[i].ReviewCount = stoi(sor);
		getline(be, sor, ',');
		adatok[i].Price = stof(sor);
		getline(be, sor);
		adatok[i].Discounted = stoi(sor);
	}
	be.close();
}

SteamStore::~SteamStore()
{
	delete[] adatok;
}

void SteamStore::Kiir(int db)
{
	if (db == -1)
		db = adatokSzama;
	cout.setf(ios::left);
	cout << setw(5) << "ID" << setw(40) << "Name" << setw(5) << "Rate" << setw(10) << "Rev. Cnt" << setw(8) << "Price" << setw(12) << "Discounted?" << endl;
	for (int i = 0;i < db; i++)
	{
		cout << setw(5) << adatok[i].GameID << setw(40) << adatok[i].Name << setw(5) << adatok[i].ReviewScore << setw(10) << adatok[i].ReviewCount << setw(8) << adatok[i].Price;
		if (adatok[i].Discounted)
			cout << setw(12) << "Discounted" << endl;
		else
			cout << setw(12) << "" << endl;
	}
}

Game SteamStore::MostReviewedGame()
{
	Game temp = adatok[0];
	for (int i = 0; i < adatokSzama; i++)
	{
		if (adatok[i].ReviewScore > temp.ReviewScore)
			temp = adatok[i];
	}
	return temp;
}

int SteamStore::DiscountedGamesCount()
{
	int db = 0;
	for (int i = 0;i < adatokSzama;i++)
	{
		if (adatok[i].Discounted)
			db++;
	}
	return db;
}

bool SteamStore::SearchByName(string adat)
{
	for (int i = 0;i < adatokSzama;i++)
	{
		if (adat == adatok[i].Name)
			return true;
	}
	return false;
}

double SteamStore::AvgPrice()
{
	double ar = 0;
	for (int i = 0;i < adatokSzama;i++)
	{
		ar += adatok[i].Price;
	}
	return ar / adatokSzama;
}

int SteamStore::AboveAvgPriceGames(double ar)
{
	int db = 0;
	for (int i = 0;i < adatokSzama;i++)
	{
		if (ar < adatok[i].Price)
			db++;
	}
	return db;
}