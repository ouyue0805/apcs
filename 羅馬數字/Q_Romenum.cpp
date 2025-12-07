#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<char, int> make_romedict() // 羅馬數字map容器
{
    return {
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
}
map<int, string> make_intdict() // 整數數字map容器
{
    return {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
}
int Decode1(string R1) // 解碼羅馬數字1
{
    map<char, int> Rome = make_romedict(); // 將羅馬數字以map裝起來
    int val = 0;
    for (int i = 0; R1[i] != '\0'; i++) // 跑一次解碼羅馬數字1，當跑到\0退出迴圈
    {
        if (R1[i + 1] != '\0' && Rome[R1[i]] < Rome[R1[i + 1]]) // 以前後兩個字元去判斷加法減法，且後字元不能為\0
        {
            val += (Rome[R1[i + 1]] - Rome[R1[i]]); // 成立時做減法
            i++;                                    // 因為做減法結合兩個字元，所以跳過下一個判斷
        }
        else
        {
            val += Rome[R1[i]]; // 做加法
        }
    }
    cout<<val<<endl;
    return val; // 回傳解碼後的數值
}
int Decode2(string R2) // 解碼羅馬數字2
{
    map<char, int> Rome = make_romedict(); // 將羅馬數字以map裝起來
    int val = 0;
    for (int i = 0; R2[i] != '\0'; i++) // 做解碼羅馬數字2
    {
        if (R2[i + 1] != '\0' && Rome[R2[i]] < Rome[R2[i + 1]])
        {
            val += (Rome[R2[i + 1]] - Rome[R2[i]]);
            i++;
        }
        else
        {
            val += Rome[R2[i]];
        }
    }
    cout<<val<<endl;
    return val; // 回傳解碼後的數值
}
void Switch_Out(int val, int i) // 進入switch去輸出對應的值/****方法1****/
{
    switch (i) // 根據丟進去的整數 輸出對應的羅馬數字
    {
    case 0: // 千位
        for (int j = 0; j < val; j++)
        {
            cout << "M";
        }
        break;
    case 1: // 百位
        if (val == 9)
        {
            cout << "CM";
        }
        else if (val == 4)
        {
            cout << "CD";
        }
        else if (val >= 5)
        {
            cout << "D";
            for (int j = 0; j < (val - 5); j++)
            {
                cout << "C";
            }
        }
        else
        {
            for (int j = 0; j < val; j++)
            {
                cout << "C";
            }
        }
        break;
    case 2: // 十位
        if (val == 9)
        {
            cout << "XC";
        }
        else if (val == 4)
        {
            cout << "XL";
        }
        else if (val >= 5)
        {
            cout << "L";
            for (int j = 0; j < (val - 5); j++)
            {
                cout << "X";
            }
        }
        else
        {
            for (int j = 0; j < val; j++)
            {
                cout << "X";
            }
        }
        break;
    case 3: // 個位
        if (val == 9)
        {
            cout << "IX";
        }
        else if (val == 4)
        {
            cout << "IV";
        }
        else if (val >= 5)
        {
            cout << "V";
            for (int j = 0; j < (val - 5); j++)
            {
                cout << "I";
            }
        }
        else
        {
            for (int j = 0; j < val; j++)
            {
                cout << "I";
            }
        }
        break;
    }
}
void Map_Out(int val, int dec) // 進入map去輸出對應的值/****方法2****/
{
    map<int, string> Out_int = make_intdict(); // 將整數數字以map裝起來
    if (val == 4 || val == 9)                  // 開頭9和開頭4特定減法輸出
    {
        cout << Out_int[val * dec];
    }
    else if (val >= 5) // 大於5先輸出5在遞減輸出
    {
        cout << Out_int[5 * dec];
        val -= 5;
        for (int j = 1; j <= val; val--)
        {
            cout << Out_int[j * dec];
        }
    }
    else // 遞減輸出
    {
        for (int j = 1; j <= val; val--)
        {
            cout << Out_int[j * dec];
        }
    }
}
void Coding(int intnum) // 進行轉換後的整數編碼
{
    int Dec = 1000;             // 宣告1000
    for (int i = 0; i < 4; i++) // 將整數拆解丟進變數整數
    {
        int Valnum;
        Valnum = intnum / Dec;
        intnum %= Dec;
        // Switch_Out(Valnum,i);//進入switch去輸出對應的值/****方法1****/
        Map_Out(Valnum, Dec); // 進入map去輸出對應的值/****方法2****/
        Dec /= 10;
    }
    cout << endl;
}
int Slove(string R1, string R2) // 計算羅馬數字的差值
{
    int num1 = 0, num2 = 0;  // 宣告整數1、2
    num1 = Decode1(R1);      // 解碼羅馬數字1
    num2 = Decode2(R2);      // 解碼羅馬數字2
    return abs(num1 - num2); // 絕對值回傳
}
void Output(string R1, string R2) // 輸出函式
{
    if (R1 == R2)
    {
        cout << "ZERO" << endl; // 如果相等輸出0
    }
    else
    {
        int Rnum;             // 宣告羅馬數字整數
        Rnum = Slove(R1, R2); // 計算羅馬數字的差值
        Coding(Rnum);         // 進行轉換後的整數編碼
    }
}
int main()
{
    string rome1, rome2; // 宣告字串羅馬數字1,2
    while (1)
    {
        cin >> rome1; // 輸入羅馬數字1
        if (rome1 == "#")
        {
            break;
        }
        cin >> rome2;         // 輸入羅馬數字2
        Output(rome1, rome2); // 輸出
    }
    return 0;
}