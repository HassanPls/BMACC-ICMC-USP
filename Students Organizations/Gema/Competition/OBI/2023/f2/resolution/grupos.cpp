#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int e, m, d;
    cin >> e >> m >> d;

    vector<pair<int,int>> mutuos(m);
    vector<pair<int,int>> distintos(d);

    for (int i = 0; i < m; i++) cin >> mutuos[i].first >> mutuos[i].second;
    for (int i = 0; i < d; i++) cin >> distintos[i].first >> distintos[i].second;
    
    vector<int> grupos(e + 1);

    int num_grupos = e/3;
    for (int i = 1; i < num_grupos + 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        grupos[x] = i;
        grupos[y] = i;
        grupos[z] = i;
    }

    int violacoes = 0;

    for (int i = 0; i < m; i++)
    {
        int x = mutuos[i].first;
        int y = mutuos[i].second;

        if (grupos[x] != grupos[y]) violacoes++;
    }

    for (int i = 0; i < d; i++)
    {
        int x = distintos[i].first;
        int y = distintos[i].second;

        if (grupos[x] == grupos[y]) violacoes++;
    }
    
    cout << violacoes;

    return 0;
}