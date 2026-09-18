#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) if (b[i] > a[i]) a[i] = b[i];
    for (int i = n - 2; i >= 0; i--) if (a[i] < a[i + 1]) a[i] = a[i+1];
    for (int i = 0; i < n; i++) if (b[i] > a[i]) a[i] = b[i];
    
    vector<int> ps(n+1);
    ps[0] = 0;
    ps[1] = a[0];
    for (int i = 2; i <= n; i++) ps[i] = ps[i-1] + a[i-1];
    
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << (ps[r] - ps[l-1]) << " ";
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
        cout << endl;
    }
    
    return 0;
}