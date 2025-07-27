#include <iostream>
using namespace std;
int num;
int i = 0;
string n;
int main()
{
    cin >> n;
    while (n[i] != '\0')
    {
        if (i % 2 == 0)
        {
            num = num + (n[i] - '0');
        }
        else
        {
            num = num - (n[i] - '0');
        }
        i++;
    }
    if (num < 0)
    {
        num = -num;
    }
    cout << num << endl;
    return 0;
}