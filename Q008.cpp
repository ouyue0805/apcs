#include <iostream>
using namespace std;
int num;
int i = 0;
int t, o, e;
int x[100];
int main()
{
    cout << "輸入你的數字:";
    cin >> num;
    //(1)
    while (num)
    {
        x[i] = num % 10;
        num/=10;
        t += x[i];
        if (i % 2 == 0)
        {
            o += x[i];
        }
        else
        {
            e += x[i];
        }
        i++;
    }
    cout << (num % 2 == 0 ? "是2的倍數" : "不是2的倍數") << endl;
    cout << (t % 3 == 0 ? "是3的倍數" : "不是3的倍數") << endl;
    cout << (num % 5 == 0 ? "是5的倍數" : "不是5的倍數") << endl;
    cout << (o == e ? "是11的倍數" : "不是11的倍數") << endl;

    //(2)
    // switch (2)
    // {
    // case 2:
    //     cout << (num % 2 == 0 ? "是2的倍數" : "不是2的倍數")<<endl;

    // case 3:
    //     cout << (num % 3 == 0 ? "是3的倍數" : "不是3的倍數")<<endl;

    // case 5:
    //     cout << (num % 5 == 0 ? "是5的倍數" : "不是5的倍數")<<endl;

    // case 11:
    //     cout << (num % 11 == 0 ? "是11的倍數" : "不是11的倍數")<<endl;

    // }
    return 0;
}