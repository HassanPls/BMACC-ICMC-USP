#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, string> dic;
    string i, p;

    for (int j = 0; j < n; j++)
    {
        cin >> i >> p;
        dic[i] = p;
    }

    string word;
    bool primeira = true;

    while (cin >> word) {
        if(!primeira) cout << " ";
        cout << dic[word];
        primeira = false;
    }

    return 0;
}