#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> tab(n, vector<int>(n));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> tab[i][j];
        }
    }

    vector<int> lin_soma(n);
    vector<int> col_soma(n);
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            lin_soma[i] += tab[i][j];
            col_soma[i] += tab[j][i];
        }
    }
    
    int maxNum = 0;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            maxNum = max(maxNum, (lin_soma[i] + col_soma[j] - (2 * tab[i][j])));
        }
        
    }
    
    cout << maxNum << "\n";

    return 0;
}