#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1001);
vector<bool> visitado(1001, false);

void dfs(int i) {
    visitado[i] = true;
    for (int v : adj[i])
    {
        if (!visitado[v]) dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int times = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visitado[i]) {
            dfs(i);
            times++;
        }
    }
    
    cout << times << "\n";

    return 0;
}