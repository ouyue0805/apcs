#include <iostream>
#include <map>
using namespace std;

int f(int num, map<int, int> &nummap)
{
    if (num == 1 || num == 2)
    {
        return 1;
    }
    else if (nummap.find(num) != nummap.end())
    {
        return nummap[num];
    }
    else
    {
        return f(num - 1, nummap) + f(num - 2, nummap);
    }
}
int main()
{
    int num;
    map<int, int> nummap;
    cin >> num;
    for (size_t i = 1; i < num; i++)
    {
        int value = f(i, nummap);
        nummap[i] = value;
    }
    double r = 0;
    for (size_t i = 2; i < num; i++)
    {
        r = (double)nummap[i] / nummap[i - 1];
        cout << r << endl;
    }
    return 0;
}