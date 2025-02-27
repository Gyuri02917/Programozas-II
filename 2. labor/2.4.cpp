#include <iostream>
using namespace std;

int main()
{
	int f = 10;
	int* mut;
	int& fi = f;
	mut = &f;
	cout << "f: " << f << " fi: " << fi << " mut: " << *mut << endl;
	fi = 20;
	cout << "f: " << f << " fi: " << fi << " mut: " << *mut << endl;
	cout << &f << " " << &fi << " " << mut << " " << &mut << endl;

	return 0;
}