#include <bits/stdc++.h>
using namespace std;

int solve() {

    stack<char> pilha;
    string s;
    int n;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        if (!pilha.empty() && pilha.top() == s[i]) {
            pilha.pop();
        } else {
            pilha.push(s[i]);
        }
    }

    if (pilha.size() > 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
    }

    return 0;
}