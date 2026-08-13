#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> faixas(n-1);
    vector<int> premiacao(n);

    for (int i = 0; i < n-1; i++) cin >> faixas[i];
    for (int i = 0; i < n; i++) cin >> premiacao[i];
    for (int i = 0; i < m; i++)
    {
        int forca;
        cin >> forca;

        auto it = upper_bound(faixas.begin(), faixas.end(), forca);

        int idx = it - faixas.begin();

        cout << premiacao[idx] << (i == m - 1 ? "":" ");
    }

    return 0;
}