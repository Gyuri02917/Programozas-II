#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct ugynok {
    string varos;
    int tav;
};

int beolvas(char*, ugynok*);
int ossztav(ugynok*, int);
string legtavolabb(ugynok*, int);
int kozeli(ugynok*, int);
void rendez(ugynok*, int);

int main()
{
    setlocale(LC_ALL, "UTF-8");
	char fnev[] = "vartav.txt";
	ugynok u[20];

	int n = beolvas(fnev, u);
	cout << "A januárban megtett távolságok összege: " << ossztav(u, n) << endl;
	cout << "A legtávolabbi város: " << legtavolabb(u, n) << endl;
	cout << "A legközelebbi városok száma: " << kozeli(u, n) << endl;
	rendez(u, n);
	
    return 0;
}

int beolvas(char* fajl, ugynok* t)
{
	ifstream be(fajl);
	if (be.fail())
	{
		cerr << "A fájl megnyitása sikertelen." << endl;
		exit(-1);
	}
	int db = 0;
	while (be >> t[db].varos >> t[db].tav)
	{
		cout << t[db].varos << " " << t[db].tav << endl;
		db++;
	}
	be.close();
	return db;
}

int ossztav(ugynok* t, int n)
{
	int ossz = 0;
	for (int i = 0; i < n; i++)
	{
		ossz += t[i].tav;
	}
	return ossz*2;
}
string legtavolabb(ugynok* t, int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (t[i].tav > t[max].tav)
		{
			max = i;
		}
	}
	return t[max].varos;
}

int kozeli(ugynok* t, int n)
{
	int tav = 0;
	for (int i = 0; i < n; i++)
	{
		if (t[i].tav < 80)
		{
			tav++;
		}
	}
	return tav;
}

void rendez(ugynok* t, int n)
{
	ugynok seged;
	ofstream ki("rendezettTavolsag.txt");
	if (ki.fail())
	{
		cerr << "A fájl megnyitása sikertelen." << endl;
		exit(-2);
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (t[i].tav > t[j].tav)
			{
				seged = t[i];
				t[i] = t[j];
				t[j] = seged;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		ki << t[i].varos << " " << t[i].tav << endl;
		cout << t[i].varos << " " << t[i].tav << endl;
	}
	ki.close();
}