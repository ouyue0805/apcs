#include <iostream>
using namespace std;
string name;
int i = 0;
int x = 0;
int main()
{
    cin >> name;
    while (name[i] != '\0')
    {
        i++;
    }
    for (int y = 0; y < ((i - 1) / 2); y++)
    {
        if (name[y] != name[(i - 1) - y])
        {
            x = 1;
        }
    }
    cout << (x == 0 ? "yes" : "no") << endl;
    return 0;
}