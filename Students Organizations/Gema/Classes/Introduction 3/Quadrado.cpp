#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matriz(3, vector<int>(3, 0));

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cin >> matriz[i][j];
        }
    }

    int sum = matriz[0][0] + matriz[0][1] + matriz[0][2];

    for (size_t i = 1; i < 3; i++)
    {
        int test = matriz[i][0] + matriz[i][1] + matriz[i][2];
        if (test != sum)
        {
            cout << "NAO";
            return 0;
        }
    }

    for (size_t i = 0; i < 3; i++)
    {
        int test = matriz[0][i] + matriz[1][i] + matriz[2][i];
        if (test != sum)
        {
            cout << "NAO";
            return 0;
        }
    }

    if (
        matriz[0][0] + matriz[1][1] + matriz[2][2] != sum ||
        matriz[0][2] + matriz[1][1] + matriz[2][0] != sum)
    {
        cout << "NAO";
        return 0;
    }

    cout << "SIM";

    return 0;
}