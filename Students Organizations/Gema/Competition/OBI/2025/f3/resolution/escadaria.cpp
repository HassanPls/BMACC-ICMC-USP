#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long inf = 1e18;

    long long n;
    cin >> n;
    vector<long long> r(n, inf), l(n, inf), a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    
    for (long long i = 0; i < n; i++)
    {
        if (a[i] != -1) {
            l[i] = a[i];
        } else if (i > 0 && l[i - 1] != inf) {
            l[i] = l[i - 1] + 1;
        }
    }

    for (long long i = n-1; i >= 0; i--)
    {
        if (a[i] != -1) {
            r[i] = a[i];
        } else if (i < n - 1 && r[i + 1] != inf) {
            r[i] = r[i + 1] + 1;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        long long ans = min(l[i], r[i]);
        cout << ans << " ";
    }
    
    return 0;
}