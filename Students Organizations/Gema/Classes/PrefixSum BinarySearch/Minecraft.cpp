#include <bits/stdc++.h>
using namespace std;

int query(int r1, int c1, int r2, int c2, int n, int m, vector<vector<int>>& pref) {
    r1 = max(r1, 1); c1 = max(c1, 1);
    r2 = min(r2, n); c2 = min(c2, m);

    if (r1 > r2 || c1 > c2) return 0;

    return pref[r2][c2] - pref[r2][c1 - 1] - pref[r1 - 1][c2] + pref[r1 - 1][c1 - 1];
}

int solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    int total_gold = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            int gold = (grid[i][j] == 'g' ? 1 : 0);
            total_gold += gold;

            pref[i + 1][j + 1] = gold + pref[i + 1][j] + pref[i][j + 1] - pref[i][j];
        }
    }
    
    int min_lost_gold = 1e9;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.') {
                int r = i + 1;
                int c = j + 1;

                int inner_box = query(r - k + 1, c - k + 1, r + k - 1, c + k - 1, n, m, pref);

                min_lost_gold = min(min_lost_gold, inner_box);
            }
        }
        
    }

    return total_gold - min_lost_gold;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << solve() << endl;
    }
    

    return 0;
}