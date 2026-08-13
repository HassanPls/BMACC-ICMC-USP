#include <bits/stdc++.h>
using namespace std;

int solve() {

    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c) {
        cout << "+" << "\n";
    } else {
        cout << "-" << "\n";
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    

    return 0;
}