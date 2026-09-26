#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c = -1, e = -1;
    int l = -1, p = -1;
    int count = 0;

    while (cin >> c >> e >> l >> p && (c != 0 || e != 0 || l != 0 || p != 0)) {

        cout << "Teste " << ++count << "\n";
        
        vector<vector<int>> estradas(c + 1);
        vector<int> dist(c + 1, -1);
        queue<int> q;
        q.push(l);
        dist[l] = 0;

        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;

            estradas[x].push_back(y);
            estradas[y].push_back(x);
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int v : estradas[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        for (int i = 1; i < c + 1; i++)
        {
            if (i != l && dist[i] != -1 && dist[i] <= p) {
                cout << i << " ";
            }
        }
        
        
        cout << "\n\n";
    }
    
    return 0;
}