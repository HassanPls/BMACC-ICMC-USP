#include <bits/stdc++.h>
using namespace std;

bool combina(char i, char f) {
    if (i == '(' && f == ')') return true;
    if (i == '[' && f == ']') return true;
    if (i == '{' && f == '}') return true;
    return false;
}

int solve() {
    string s;
    cin >> s;

    stack<char> pilha;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            pilha.push(s[i]);
        } else {
            if (pilha.size() > 0) {
                if (combina(pilha.top(), s[i])) {
                    pilha.pop();
                } else {
                    cout << "N\n";
                    return 0;
                }
            } else {
                cout << "N\n";
                return 0;
            }
        }
    }
    
    if (pilha.size() > 0) {
        cout << "N\n";
    } else {
        cout << "S\n";
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