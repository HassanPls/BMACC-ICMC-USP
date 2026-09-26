#include <bits/stdc++.h>
using namespace std;

bool balanceado = true;

int dfs(int v, vector<vector<int>>& grafo) {

    int primeiro_peso = -1;
    int peso_total = 1;

    for(int u : grafo[v]) {
        int peso_filhos = dfs(u, grafo);
        peso_total += peso_filhos;

        if (primeiro_peso == -1) {
            primeiro_peso = peso_filhos;
        } else if (primeiro_peso != peso_filhos) {
            balanceado = false;
        }
    }
    return peso_total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> mobiles(n + 2);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        mobiles[v].push_back(u);
    }

    dfs(0, mobiles);
    
    if (balanceado) {
        cout << "bem";
    } else {
        cout << "mal";
    }

    return 0;
}