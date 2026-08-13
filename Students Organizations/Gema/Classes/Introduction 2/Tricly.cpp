#include <bits/stdc++.h>
using namespace std;

string solve() {

    int n = 0;
    cin >> n;
    string a = "", b = "", c = "";
    cin >> a >> b >> c;
    string result = "YES";

    for (int i = 0; i < n; i++)
    {
        if (c[i] != a[i] && c[i] != b[i]) {
            return "YES";
        }
    }
    

    return "NO";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << solve() << "\n";
    }

    return 0;
}