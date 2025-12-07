#include <iostream>
using namespace std;

float getDet(float(A)[2][2])
{
    return A[0][0] * A[1][1] - (A[0][1] * A[1][0]);
}

void getInverseMatrix(float A[2][2], float inverseA[2][2])
{

    float temp = A[0][0];
    inverseA[0][0] = A[1][1];
    inverseA[1][1] = temp;
    inverseA[0][1] = -(A[0][1]);
    inverseA[1][0] = -(A[1][0]);
}

void multiplyByConst(float c, float A[2][2], float result[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int o = 0; o < 2; o++)
        {
            result[i][o] = (A[i][o]) / c;
        }
    }
}

void multiplyTwoMatrix(float A[2][2], float B[2][1], float X[2][1])
{
    for (int j = 0; j < 2; j++)
    {
        X[j][0] = 0;
        for (int k = 0; k < 2; k++)
        {
            X[j][0] += (A[k][j] * B[k][0]);
        }
    }
}

void solve(float A[2][2], float B[2][1], float X[2][1])
{
    float detA = getDet(A);
    if (detA == 0)
    {
        cout << "A矩陣沒有乘法反方陣" << "\n";
        return;
    }
    float inverseA[2][2];
    getInverseMatrix(A, inverseA);
    float result[2][2];
    multiplyByConst(detA, inverseA, result);
    multiplyTwoMatrix(result, B, X);
    cout << X[0][0] << endl;
    cout << X[1][0] << endl;
}

int callbyvalue(int x)
{
    x = 10;
    return x;
}

int callbyreference(int &x)
{
    x = 10;
    return x;
}

void inputAMatrix(float(A)[2][2])
{
    cout << "輸入A:" << "\n";
    for (int i = 0; i < 2; i++)
    {
        for (int o = 0; o < 2; o++)
        {
            cin >> A[o][i];
        }
    }
}

void inputBMatrix(float(B)[2][1])
{
    cout << "輸入解C:" << "\n";
    for (int k = 0; k < 2; k++)
    {
        cin >> B[k][0];
    }
}

int main()
{
    // int x = 4;
    // callbyvalue(x);
    // cout << x << endl;
    // callbyreference(x);
    // cout << x << endl;

    float A[2][2];
    float B[2][1];
    float X[2][1];

    inputAMatrix(A);
    inputBMatrix(B);
    solve(A, B, X);
    // cout << X[0][0] << endl;
    // cout << X[1][0] << endl;

    return 0;
}