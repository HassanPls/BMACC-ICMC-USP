#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> cidades(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> cidades[i];
    }

    vector<long long> torres(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> torres[i];
    }
    
    long long r_minimo = 0;
    for (size_t i = 0; i < n; i++)
    {
        long long pos_cidade = cidades[i];

        auto it_dir = upper_bound(torres.begin(), torres.end(), pos_cidade);

        long long dist_min_cidade = 2e18;

        if (it_dir != torres.end()) {
            dist_min_cidade = min(dist_min_cidade, *it_dir - pos_cidade);
        }

        if (it_dir != torres.begin()) {
            auto it_esq = it_dir;
            it_esq--;
            dist_min_cidade = min(dist_min_cidade, pos_cidade - *it_esq);
        }

        r_minimo = max(r_minimo, dist_min_cidade);
    }
    
    cout << r_minimo << "\n";

    return 0;
}