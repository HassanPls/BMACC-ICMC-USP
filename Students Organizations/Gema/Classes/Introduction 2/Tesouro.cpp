#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    string comandos = "";
    cin >> comandos;

    for (int i = 0; i < n; i++)
    {
        if (comandos[i] == 'C') {
            x--;
        } else if (comandos[i] == 'B') {
            x++;
        } else if (comandos[i] == 'D') {
            y++;
        } else if (comandos[i] == 'E') {
            y--;
        }
    }

    cout << x << " " << y;
    

    return 0;
}