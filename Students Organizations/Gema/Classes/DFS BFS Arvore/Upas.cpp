#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    vector<vector<int>> conflitos(n + 1);
    vector<bool> bloqueados(n+1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        conflitos[u].push_back(v);
        conflitos[v].push_back(u);
    }

    vector<int> escolhidos;

    for (int i = n; i >= 1; i--)
    {
        if (!bloqueados[i]) {
            escolhidos.push_back(i);

            for (int vizinhos : conflitos[i])
            {
                bloqueados[vizinhos] = true;
            }
            
        }
    }

    reverse(escolhidos.begin(), escolhidos.end());

    cout << escolhidos.size() << "\n";
    for (int i = 0; i < escolhidos.size(); i++)
    {
        cout << escolhidos[i] << " ";
    }

    return 0;
}