#include <iostream>
#include <cmath>
using namespace std;
int num;
int i = 2;
int x;
bool y;
int main()
{
    cout << "請輸入你的數字(請大於1):";
    cin >> num;
    while (i <= sqrt(num))
    {
        if (num % i==0) 
        {
            y = 1;
            break;
        }
        else if (num % i!=0)
        {
            y = 0;
        }
        i++;
    }
    if (y == 0)
    {
        cout << "此數為質數" << endl;
    }
    else if (y == 1)
        cout << "此數不為質數" << endl;
    return 0;
}