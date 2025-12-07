#include <iostream>
using namespace std;
int num[4];
int a;
int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> num[i];
    }
    a = num[0] * num[1] * num[2] + num[3];
    
    cout << num[0] << "   " << num[1] << endl;
    cout << "  " << a << "    " << endl;
    cout << num[2] << "   " << num[3] << endl;
    return 0;
}