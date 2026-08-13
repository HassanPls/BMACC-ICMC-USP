#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
    int total = 1;
    if (n <= k) {
        return total;
    } else {
        int a = n/2;
        int b = n - a;
        return solve(a, k) + solve(b, k);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = -1, k = -1;

    while (cin >> n >> k && n !=0 && k != 0)
    {
        cout << solve(n, k) << "\n";
    }

    return 0;
}