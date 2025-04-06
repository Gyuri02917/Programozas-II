#include <iostream>
using namespace std;

class Sokszog
{
protected:
	int a, b;
public:
	Sokszog(int a, int b) : a(a), b(b) {}
};

class Negyzet : public Sokszog
{
public:
	Negyzet(int a) : Sokszog(a, a) {}
	int terulet() { return a * a; }
};

class Teglalap : public Sokszog
{
public:
	Teglalap(int a, int b) : Sokszog(a, b) {}
	int terulet() { return a * b; }
};

class Haromszog : public Sokszog
{
public:
	Haromszog(int a, int b) : Sokszog(a, b) {}
	int terulet() { return a * b / 2; }
};

int main()
{
	setlocale(LC_ALL, "hun");
	Negyzet n(5);
	Teglalap t(3, 4);
	Haromszog h(3, 4);
	cout << "Negyzet ter�lete: " << n.terulet() << endl;
	cout << "Teglalap ter�lete: " << t.terulet() << endl;
	cout << "Haromszog ter�lete: " << h.terulet() << endl;

	return 0;
}