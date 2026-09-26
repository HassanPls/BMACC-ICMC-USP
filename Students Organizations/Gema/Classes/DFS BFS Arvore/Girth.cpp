#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grafo(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    int menorTamanho = 1e9;

    for (int i = 1; i < n+1; i++)
    {
        queue<int> q;
        vector<int> dist(n + 1, -1);
        vector<int> parent(n + 1, -1);

        q.push(i);
        dist[i] = 0;

        while (!q.empty())
        {
            int no = q.front();
            q.pop();

            if (dist[no] >= menorTamanho) break;

            for (int v : grafo[no])
            {
                if (dist[v] == -1) {
                    dist[v] = dist[no] + 1;
                    parent[v] = no;
                    q.push(v);
                } else if (v != parent[no]) {
                    int ciclo = dist[no] + dist[v] + 1;
                    menorTamanho = min(ciclo, menorTamanho);
                }
            }
            
        }
    }
    
    if (menorTamanho == 1e9) {
        cout << -1;
    } else {
        cout << menorTamanho;
    }
    
    return 0;
}