#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<set<int>> pontes(n + 1);

    for (int i = 0; i < m; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 0) {
            cout << pontes[a].count(b) << "\n";
        } else {
            pontes[a].insert(b);
            pontes[b].insert(a);
        }
    }    

    return 0;
}