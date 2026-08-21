#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> usado(20, false);
vector<int> proibido[20];

int res(int x) {
    if (x == n) return 1;
    int ret = res(x+1);

    bool ok = true;
    for(int v : proibido[x]) {
        if (usado[v]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        usado[x] = true;
        ret += res(x + 1);
        usado[x] = false;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        proibido[x].push_back(y);
        proibido[y].push_back(x);
    }

    cout << res(0) - 1;
    
    return 0;
}