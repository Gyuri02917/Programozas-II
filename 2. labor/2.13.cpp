#include <iostream>
using namespace std;

int main(int argdb, char* argtomb[])
{
	//Hagyományosan a program feladata: float a, b; cout << "Adjon meg két számot: "; cin >> a, b; cout << a*b << endl;

	if (argdb != 3)
	{
		cerr << "Hiba, a program nem indítható! Helyes paraméterezés: " << argtomb[0] << " szam1 szam2" << endl;
		//Jelen esetben az argtomb[0] a program indítási helyét adja meg, windwos-on pl C:\Users\[username]\source\repos\...\project.exe
		return 1;
	}

	float a, b;
	a = atof(argtomb[1]);
	b = atof(argtomb[2]);
	cout << a << " * " << b << " = " << a * b << endl;

	return 0;
}
