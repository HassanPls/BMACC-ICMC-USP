#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> interval(m);

    for (size_t i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << ((i % 2 == 0) ? "0":"1");
    }
    

    return 0;
}