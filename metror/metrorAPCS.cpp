#include <iostream>
#include <vector>
using namespace std;


void soberDinosaur(int L, int W, int &SoberDinosaur, vector<vector<int>> &Dinosaurmap)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (Dinosaurmap[i][j] > 0)
            {
                SoberDinosaur += Dinosaurmap[i][j];
            }
        }
    }
}
void highandlow(int L, int W, int &Highest, int &Lowest, vector<vector<int>> &Highmap)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (Highmap[i][j] > Highest)
            {
                Highest = Highmap[i][j];
            }
            if (Highmap[i][j] < Lowest)
            {
                Lowest = Highmap[i][j];
            }
        }
    }
}
void Calculate(int L, int W, vector<vector<int>> &Highmap, vector<vector<int>> &Dinosaurmap)
{
    int Highest = Highmap[0][0];
    int Lowest = Highmap[0][0];
    int SoberDinosaur = 0;
    highandlow(L, W, Highest, Lowest, Highmap);
    soberDinosaur(L, W, SoberDinosaur, Dinosaurmap);
    cout << Highest << " " << Lowest << " " << SoberDinosaur << endl;
}
void Hittheground(int L, int W, int metrorX, int metrorY, int metrorLength, int metrorPower, vector<vector<int>> &Highmap)
{
    for (int j = (metrorX - (metrorLength / 2)); j <= (metrorX + (metrorLength / 2)); j++)
    {
        if (j < 0 || j >= L)
        {
            continue;
        }
        for (int k = (metrorY - (metrorLength / 2)); k <= (metrorY + (metrorLength / 2)); k++)
        {
            if (k < 0 || k >= W)
            {
                continue;
            }
            Highmap[j][k] -= metrorPower;
        }
    }
}
void DizzyDinosaur(int L, int W, int metrorX, int metrorY, int metrorLength, bool &attackEarth, vector<vector<int>> &Dinosaurmap)
{
    for (int j = (metrorX - (metrorLength / 2)); j <= (metrorX + (metrorLength / 2)); j++)
    {
        if (j < 0 || j >= L)
        {
            continue;
        }
        for (int k = (metrorY - (metrorLength / 2)); k <= (metrorY + (metrorLength / 2)); k++)
        {
            if (k < 0 || k >= W)
            {
                continue;
            }
            if (Dinosaurmap[j][k] > 0)
            {
                attackEarth = false;
                Dinosaurmap[j][k] = 0;
            }
        }
    }
}
void attackEarth(int L, int W, vector<vector<int>> &Highmap, vector<vector<int>> &Dinosaurmap)
{
    int metror;
    cin >> metror;
    for (int i = 0; i < metror; i++)
    {
        int metrorX, metrorY, metrorLength, metrorPower;
        bool attackEarth = true;
        cin >> metrorX;
        cin >> metrorY;
        cin >> metrorLength;
        cin >> metrorPower;
        DizzyDinosaur(L, W, metrorX, metrorY, metrorLength, attackEarth, Dinosaurmap);
        if (attackEarth == true)
        {
            Hittheground(L, W, metrorX, metrorY, metrorLength, metrorPower, Highmap);
        }
    }
}
void Heightset(int L, int W, int High, vector<vector<int>> &Highmap)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            Highmap[i][j] = High;
        }
    }
}
void Dinosaurset(int L, int W, int Dinosaur, vector<vector<int>> &Dinosaurmap)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            Dinosaurmap[i][j] = 0;
        }
    }
    for (int i = 0; i < Dinosaur; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        if (a >= 0 && a < L && b >= 0 && b < W)
        {
            Dinosaurmap[a][b]++;
        }
    }
}
void setting()
{
    int L, W, High, Dinosaur;
    cin >> L;
    cin >> W;
    cin >> High;
    cin >> Dinosaur;
    vector<vector<int>> Highmap(L, vector<int>(W));
    vector<vector<int>> Dinosaurmap(L, vector<int>(W));
    Heightset(L, W, High, Highmap);
    Dinosaurset(L, W, Dinosaur, Dinosaurmap);
    attackEarth(L, W, Highmap, Dinosaurmap);
    Calculate(L, W, Highmap, Dinosaurmap);
}

int main()
{
    /*抽成函數*/
    setting();
    /*一次性程式*/
    // int L, W, High, Dinosaur, metror;
    // cin >> L;
    // cin >> W;
    // cin >> High;
    // cin >> Dinosaur;
    // int Highmap[L][W];
    // int Dinosaurmap[L][W];
    // for (int i = 0; i < L; i++)
    // {
    //     for (int j = 0; j < W; j++)
    //     {
    //         Dinosaurmap[i][j] = 0;
    //     }
    // }
    // for (int i = 0; i < Dinosaur; i++)
    // {
    //     int a, b;
    //     cin >> a;
    //     cin >> b;
    //     if (a >= 0 && a < L && b >= 0 && b < W)
    //     {
    //         Dinosaurmap[a][b]++;
    //     }
    // }
    // cin >> metror;
    // for (int i = 0; i < metror; i++)
    // {
    //     int metrorX, metrorY, metrorLength, metrorPower;
    //     bool attackEarth = true;
    //     cin >> metrorX;
    //     cin >> metrorY;
    //     cin >> metrorLength;
    //     cin >> metrorPower;
    //     for (int j = (metrorX - (metrorLength / 2)); j <= (metrorX + (metrorLength / 2)); j++)
    //     {
    //         if (j < 0 || j >= L)
    //         {
    //             continue;
    //         }
    //         for (int k = (metrorY - (metrorLength / 2)); k <= (metrorY + (metrorLength / 2)); k++)
    //         {
    //             if (k < 0 || k >= W)
    //             {
    //                 continue;
    //             }
    //             if (Dinosaurmap[j][k] > 0)
    //             {
    //                 attackEarth = false;
    //                 Dinosaurmap[j][k] = 0;
    //             }
    //         }
    //     }
    //     if (attackEarth == true)
    //     {
    //         for (int j = (metrorX - (metrorLength / 2)); j <= (metrorX + (metrorLength / 2)); j++)
    //         {
    //             if (j < 0 || j >= L)
    //             {
    //                 continue;
    //             }
    //             for (int k = (metrorY - (metrorLength / 2)); k <= (metrorY + (metrorLength / 2)); k++)
    //             {
    //                 if (k < 0 || k >= W)
    //                 {
    //                     continue;
    //                 }
    //                 Highmap[j][k] -= metrorPower;
    //             }
    //         }
    //     }
    // }
    // int Highest = Highmap[0][0];
    // int Lowest = Highmap[0][0];

    // for (int i = 0; i < L; i++)
    //     for (int j = 0; j < W; j++)
    //     {
    //         if (Highmap[i][j] > Highest)
    //         {
    //             Highest = Highmap[i][j];
    //         }
    //         if (Highmap[i][j] < Lowest)
    //         {
    //             Lowest = Highmap[i][j];
    //         }
    //     }
    // int SoberDinosaur = 0;
    // for (int i = 0; i < L; i++)
    // {
    //     for (int j = 0; j < W; j++)
    //     {
    //         if (Dinosaurmap[i][j] > 0)
    //         {
    //             SoberDinosaur += Dinosaurmap[i][j];
    //         }
    //     }
    // }
    // cout << Highest << " " << Lowest << " " << SoberDinosaur << endl;
    return 0;
}