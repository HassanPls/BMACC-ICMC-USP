#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<bool> dicAlien(256, false);
    string message;

    for (int i = 0; i < k; i++) {
        char x;
        cin >> x;
        dicAlien[(unsigned char)x] = true;
    }

    cin >> message;
    
    for (int i = 0; i < n; i++)
    {
        if (!dicAlien[(unsigned char)message[i]]) {
            cout << "N\n";
            return 0;
        }
    }
    
    cout << "S\n";

    return 0;
}