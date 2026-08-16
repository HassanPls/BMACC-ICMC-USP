#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long expo(long long a, long long b) {
    if (b == 0) return 1;

    long long div = expo(a, b/2);
    long long result = (div * div) % MOD;

    if (b % 2 != 0) {
        result = (result * (a % MOD)) % MOD;
    }

    return result;
}

void solve() {

    long long a, b;
    cin >> a >> b;

    cout << expo(a, b) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}