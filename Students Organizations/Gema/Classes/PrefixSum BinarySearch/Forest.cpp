#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> ps(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;

        for (int j = 1; j <= n; j++)
        {
            int isTree = (row[j - 1] == '*' ? 1 : 0);
            ps[i][j] = isTree 
                        + ps[i - 1][j] 
                        + ps[i][j - 1] 
                        - ps[i - 1][j - 1];
        }
        
    }
    
    for (int i = 0; i < q; i++)
    {
        int y1, y2, x1, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int ans = ps[y2][x2] - ps[y1 - 1][x2] - ps[y2][x1 - 1] + ps[y1 - 1][x1 - 1];

        cout << ans << "\n";    
    }
    
    return 0;
}