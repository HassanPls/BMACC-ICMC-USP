#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string p, s;
    cin >> n;
    cin >> p;
    cin >> m;
    cin >> s;

    int total = 0;

    for (int i = 0; i < min(n, m); i++)
    {
        if (s[i] == p[i]) {
            total++;
        } else {
            cout << total;
            return 0;
        }
    }
    
    cout << total;

    return 0;
}