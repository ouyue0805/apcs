#include <iostream>
using namespace std;
float worse_score = -1;
int best_score = 101;
int stu_num;
int temp;
int temp1;
int score[0];
void N_U_M(int x)
{
    for (int u=0; u < x; u++)
    {
        for (int p = 0; p < x; p++)
        {
            if (score[p] < score[p + 1])
            {
                temp = score[p];
                score[p] = score[p + 1];
                score[p + 1] = temp;
            }
        }
    }
    for (int y = x-1; y >= 0; y--)
    {
        cout << score[y] << " ";
    }
}
int main()
{
    cout << "學生人數:";
    cin >> stu_num;
    score[stu_num];
    cout << "學生分數:";
    for (int i = 0; i < stu_num; i++)
    {
        cin >> score[i];
    }
    for (int n = 0; n < stu_num; n++)
    {
        if (score[n] >= worse_score && score[n] < 60)
        {
            worse_score = score[n];
        }
        else if (score[n] <= best_score && score[n] > 60)
        {
            best_score = score[n];
        }
    }
    if (best_score > 100)
    {
        cout << "best_score" << endl;
        cout << "最不幸的分數:" << worse_score << endl;
    }
    else if (worse_score < 0)
    {
        cout << "最幸運的分數:" << best_score << endl;
        cout << "worse_score" << endl;
    }
    else if (best_score <= 100 && worse_score >= 0)
    {
        cout << "最幸運的分數:" << best_score << endl;
        cout << "最不幸的分數:" << worse_score << endl;
    }
    N_U_M(stu_num);
    return 0;
}
