#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    int gaiolasNeeded = 1 + ((n-1) * 5);

    if (m >= gaiolasNeeded) {
        cout << "S";
    } else {
        cout << "N";
    }

    return 0;
}