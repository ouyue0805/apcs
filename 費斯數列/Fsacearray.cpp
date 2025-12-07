#include <iostream>
using namespace std;
int f(int num)
{
    if (num == 1 || num == 2)
    {
        return 1;
    }
    else
    {
        return f(num - 1) + f(num - 2);
    }
}
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << f(i) << endl;
    }
    return 0;
}