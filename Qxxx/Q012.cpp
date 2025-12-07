#include <iostream>
#include <string>
using namespace std;
string Dectobin(string q, int n)
{
    for (int i = 1; i <= 6; i++)
    {
        // q = (n % 2 == 1 ? "1" : "0") + q; // 用三源運算子
        // if (n == 1)
        // {
        //     break;
        // }
        int bin = n % 2; // 用string程式庫使用to_string()函式把整數改成字串
        q = to_string(bin) + q;
        n = n / 2;
    }
    return q;
}
void Outbin(string q)
{
    int n, m;
    for (m = 1; m <= 32; m++)
    {
        n = m;
        string q;
        q = Dectobin(q, n);
        cout << m << " " << q << endl;
    }
}
int getDecNum(string bin, int N[6], int Dec, int num, int pow)
{
    N[6] = 0, num = 0, pow = 1;
    for (int o = 0; o < bin.size(); o++)
    {
        N[o] = Dec % 10;
        Dec = Dec / 10;
        num = num + N[o] * pow;
        pow = pow * 2;
    }
    return num;
}
void getintDec(string bin)
{
    int Dec = stoi(bin);
    int N[6], num, pow;
    num = getDecNum(bin, N, Dec, num, pow);
    cout << num << endl;
}
int main()
{
    // 十進轉二進
    // string q;
    // Outbin(q);
    // 二進轉十進
    string bin;
    cin >> bin;
    getintDec(bin);
    return 0;
}