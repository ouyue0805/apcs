#include <iostream>
using namespace std;
int a, b;
int main()
{
    while(cin >> a >> b)
    {
        int v[a][b];
        for (int x = 0; x < a; x++)
        {
            for (int y = 0; y < b; y++)
            {
                cin >> v[x][y];
            }
        }
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < a; k++)
            {
                cout << v[k][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}