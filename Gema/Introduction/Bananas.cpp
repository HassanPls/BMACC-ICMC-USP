#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k, w, n;

    cin >> k >> n >> w;

    long long total = (w * (w+1) /2) * k;
    cout << max(0LL, total - n) << "\n";

    return 0;
}