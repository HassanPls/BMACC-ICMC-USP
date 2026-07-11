#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<int>> mar(100, vector<int>(100, 0));
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int xi = 0, xf = 0, yi = 0, yf = 0;
        cin >> xi >> xf >> yi >> yf;

        for (int j = yi; j < yf; j++)
        {
            for (int k = xi; k < xf; k++)
            {
                mar[j][k] = 1;
            }
        }
    }

    int total = 0;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            total += mar[i][j];
        }
    }

    cout << total;

    return 0;
}