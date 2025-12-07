#include <iostream>
using namespace std;
int main()
{
    for (int i = 0; i <= 4; i++)
    {
        for (int n=1; n <= ((i * 2) - 1); n++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int q = 3; q >= 1; q--)
    {
        for (int z=1; z <= ((q * 2) - 1); z++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}