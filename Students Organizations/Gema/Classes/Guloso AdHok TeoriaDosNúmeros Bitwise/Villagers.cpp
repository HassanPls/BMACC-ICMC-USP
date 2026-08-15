#include <bits/stdc++.h>
using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<long long> g(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    
    sort(g.begin(), g.end());

    long long total = 0;

    for (int i = n - 1; i >= 0; i-= 2)
    {
        total += g[i];
    }

    return total;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << solve() << "\n";
    }

    return 0;
}