#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<bool> &vi, vector<vector<int>> &a) {
    vi[i] = true;

    for(int v : a[i]) {
        if (!vi[v]) dfs(v, vi, a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int blocks = 0;
    vector<int> blocks_union;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) {
            dfs(i, visited, adj);
            blocks++;
            blocks_union.push_back(i);
        }
    }
    
    cout << blocks - 1 << "\n";
    for (int i = 0; i < blocks_union.size()-1; i++)
    {
        cout << blocks_union[i] << " " << blocks_union[i+1] << "\n";
    }
    

    return 0;
}