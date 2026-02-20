#include <iostream>
using namespace std;

#define PI 3.14159

inline double atvalt(double fok);
double terulet(double a, double b, double gamma);

int main()
{
	setlocale(LC_ALL, "hun");
	double a, b, gamma;
	cout << "Adja meg a háromszög két oldalát, és a bezárt szöget!" << endl;
	cout << "a = " << endl;
	cin >> a;
	cout << "b = " << endl;
	cin >> b;
	cout << "gamma = " << endl;
	cin >> gamma;
	
	cout << "Terület: " << terulet(a, b, gamma) << endl;	

	return 0;
}

inline double atvalt(double fok)
{
	return fok * PI / 180;
}

double terulet(double a, double b, double gamma)
{
	return a * b * sin(atvalt(gamma)) / 2;
}