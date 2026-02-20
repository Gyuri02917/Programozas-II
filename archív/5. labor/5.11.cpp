#include <iostream>
using namespace std;

double terulet(int, int);
double terulet(double, double);
double terulet(float, float);

int main()
{
	setlocale(LC_ALL, "hun");
	cout << "A négyzet területei a következőek: " << endl;
	cout << terulet(20, 5) << endl;
	cout << terulet(20.8, 5.2) << endl;
	float x = 20.7, y = 5.1;
	cout << terulet(x, y) << endl;

	return 0;
}

double terulet(int a, int b)
{
	return a*b;
}

double terulet(double a, double b)
{
	return a*b;
}

double terulet(float a, float b)
{
	return a*b;
}