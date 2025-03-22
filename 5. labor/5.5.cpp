#include <iostream>
#include <iomanip>
using namespace std;

struct tanulo
{
	char neve[25];
	int jegy;
	int tankor;
};

int main()
{
	ifstream be("tanulo.dat", ios::binary);
	int db;
	tanulo csop;
	if ( be.fail())
	{
		cout<<"HIBAS FILE MEGNYITAS ";
		return (-1);
	}
	
	while(!be.eof())
	{
		be.read((char*)&csop,sizeof(csop));
		if(!be.eof())
		{
			cout<<setw(25)<<csop.neve<<setw(6)<<csop.jegy<<setw(5)<<csop.tankor<<endl;
		}
	}
	be.close();

	return 0;
}

