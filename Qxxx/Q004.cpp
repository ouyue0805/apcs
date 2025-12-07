#include <iostream>
using namespace std;
int triangle[3];
int temp;
int main()
{
    for (int t = 0; t < 3; t++)
    {
        cin >> triangle[t];
    }
    for (int b = 0; b < 3; b++)
    {
        for (int o = 0; o < 3; o++)
        {
            if (triangle[o] < triangle[o + 1])
            {
                temp = triangle[o];
                triangle[o] = triangle[o + 1];
                triangle[o + 1] = temp;
            }
        }
    }
    for (int u = 2; u >= 0; u--)
    {
        cout << triangle[u] << " ";
    }
    cout << endl;
    if (triangle[1] + triangle[2] > triangle[0])
    {
        if ((triangle[1] * triangle[1]) + (triangle[2] * triangle[2]) < (triangle[0] * triangle[0]))
        {
            cout << "Obtuse" << endl;
        }
        else if ((triangle[1] * triangle[1]) + (triangle[2] * triangle[2]) == (triangle[0] * triangle[0]))
        {
            cout << "Right" << endl;
        }
        else if ((triangle[1] * triangle[1]) + (triangle[2] * triangle[2]) > (triangle[0] * triangle[0]))
        {
            cout << "Acute" << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}