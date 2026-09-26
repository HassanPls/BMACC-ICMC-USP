#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> parent(n + 1, 0);
    queue<int> q;

    q.push(1);
    parent[1] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == n) break;

        for(int v : adj[u]) {
            if (parent[v] == 0) {
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    if (parent[n] == 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;
    for (int cur = n; cur != -1; cur=parent[cur]) {
        path.push_back(cur);
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++)
    {
        cout << path[i] << " ";
    }
    
    return 0;
}