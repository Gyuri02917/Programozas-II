#include <iostream>
#include <ctime>
using namespace std;

int* LottoHuzas(int);
void Kiir(int*, int);

int main()
{
    setlocale(LC_ALL, "UTF-8");
    srand((unsigned)time(NULL));
    bool kilep = false;
    while(!kilep)
    {
        int n;
        do {
            cout << "Hány számot szeretne húzni? (5, 6, 7): ";
            cin >> n;
            if(cin.fail())
            {
                cin.clear();
                cout << "Nem számot adott meg!" << endl;
            }
            cin.ignore();
        } while (n > 7 || n < 5);
        int* t = LottoHuzas(n);
        Kiir(t, n);
        delete[] t;
        cout << "Szeretne még húzni? (0 - nem, 1 - igen): ";
        cin >> kilep;
        cin.ignore();
        kilep = !kilep;
    }

    return 0; 
}

int* LottoHuzas(int n)
{
    int* t = new int[n];
    for (int i = 0; i < n; i++)
    {
        switch (n)
        {
        case 5:
            t[i] = rand() % 90 + 1;
            break;
        case 6:
            t[i] = rand() % 45 + 1;
            break;
        case 7:
            t[i] = rand() % 35 + 1;
            break;
        default:
            cout << "Nem megfelelő számot adott meg!" << endl;
            break;
        }
        for(int j = 0; j < i; j++)
        {
            if(t[i] == t[j])
            {
                i--;
                break;
            }
        }
    }
    return t;
}

void Kiir(int* t, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
}