#include <iostream>
using namespace std;

void Hanoi(int, char, char, char);

int main()
{
	setlocale(LC_ALL, "UTF-8");
	cout << "Hanoi tornyai 3 koronggal :" << endl;
	Hanoi(3, 'A', 'B', 'C');

	return 0;
}

void Hanoi(int N,char Honnan,char Mivel,char Hova)
{
	if(N>0)
	{
		Hanoi(N-1,Honnan,Hova,Mivel);
		cout << N << ". korongot tegye " << Honnan << " rúdról " << Hova << " rúdra!" << endl;
		Hanoi(N-1,Mivel,Honnan,Hova);
	}
}