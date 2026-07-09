#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n = 0;
    cin >> n;
    string s = "", newS = "";
    cin >> s;

    if (n <= 3) {
        return s;
    }

    int added = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 3 > n-1) break;

        if (
            (s[i] == 'b' || s[i] == 'c' || s[i] == 'd') && 
            (s[i+1] == 'a' || s[i+1] == 'e') && 
            (s[i+2] == 'b' || s[i+2] == 'c' || s[i+2] == 'd') &&
            (s[i+3] == 'b' || s[i+3] == 'c' || s[i+3] == 'd')
        ) {
            newS.push_back(s[i]);
            newS.push_back(s[i+1]);
            newS.push_back(s[i+2]);
            newS.push_back('.');
            i+=2;
            added+=3;
        } else {
            newS.push_back(s[i]);
            newS.push_back(s[i+1]);
            newS.push_back('.');
            i++;
            added+=2;
        }
    }
    
    for (int i = 0; i < n-added; i++)
    {
        newS.push_back(s[added + i]);
    }
    
    return newS;

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