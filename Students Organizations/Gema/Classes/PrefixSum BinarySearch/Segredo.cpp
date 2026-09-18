#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> ps(10, vector<int>(n, 0));
    ps[nums[0]][0]++;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ps[j][i] = ps[j][i - 1] + (nums[i] == j ? 1 : 0);
        }
        
    }
    
    int prev;
    cin >> prev;
    prev--;
    vector<int> ans(10, 0);

    for (int i = 1; i < m; i++)
    {
        int cur;
        cin >> cur;
        cur--;

        int a = min(prev, cur);
        int b = max(prev, cur);

        for (int j = 0; j < 10; j++)
        {
            if (prev < cur) ans[j] += ps[j][cur] - ps[j][prev];
            else ans[j] += ps[j][prev - 1] - ps[j][cur - 1];
        } 

        prev = cur;
    }

    ans[nums[0]]++;
    
    for (int j = 0; j < 10; j++)
    {
        cout << ans[j] << " ";
    } 

    return 0;
}