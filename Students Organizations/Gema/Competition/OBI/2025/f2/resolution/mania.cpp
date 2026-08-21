#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    long long totalA = 0, totalB = 0;

    vector<vector<int>> matA = g;
    vector<vector<int>> matB = g;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 == 0) {
                if (matA[i][j] % 2 != 0) {
                    matA[i][j]++;
                    totalA++;
                }
            } else {
                if (matA[i][j] % 2 == 0) {
                    matA[i][j]++;
                    totalA++;
                }
            }
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 == 0) {
                if (matB[i][j] % 2 == 0) {
                    matB[i][j]++;
                    totalB++;
                }
            } else {
                if (matB[i][j] % 2 != 0) {
                    matB[i][j]++;
                    totalB++;
                }
            }
        }
    }

    cout << min(totalA, totalB) << "\n";
    
    if (totalA < totalB) {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matA[i][j] << (j == (m-1) ? "" : " ");
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matB[i][j] << (j == (m-1) ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}