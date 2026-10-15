#include <bits/stdc++.h>
using namespace std;

struct Aresta {
    int tipo;
    int u, v;

    bool operator<(const Aresta& outra) const {
        return tipo < outra.tipo;
    }
};

vector<int> pai;

void inicializar(int n) {
    pai.resize(n + 1);
    for (int i = 1; i <= n; i++) pai[i] = i;
}

int find(int v) {
    if (v == pai[v]) return v;
    return pai[v] = find(pai[v]);
}

bool unite(int u, int v) {
    int chefe_u = find(u);
    int chefe_v = find(v);

    if (chefe_u != chefe_v) {
        pai[chefe_u] = chefe_v;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<Aresta> aresta(m);
    for (int i = 0; i < m; i++)
    {
        cin >> aresta[i].u >> aresta[i].v >> aresta[i].tipo ;
    }

    sort(aresta.begin(), aresta.end());

    inicializar(n);

    int total_remocoes = 0;

    for (int i = 0; i < m; i++)
    {
        bool uniu = unite(aresta[i].u, aresta[i].v);

        if (!uniu) {
            if (aresta[i].tipo == 1) {
                cout << "N\n";
                return 0;
            } else {
                total_remocoes++;
            }
        }
    }

    if (total_remocoes > k) {
        cout << "N";
    } else {
        cout << "S";
    }

    return 0;
}