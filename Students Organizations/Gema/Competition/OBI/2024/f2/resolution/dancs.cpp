#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, p;
    cin >> n >> m >> p;

    vector<long long> linhas(n + 1);
    vector<long long> colunas(m + 1);

    for (long long i = 0; i <= n; i++) linhas[i] = i;
    for (long long i = 0; i <= m; i++) colunas[i] = i;

    for (long long i = 0; i < p; i++)
    {
        char z;
        cin >> z;
        long long x, y;
        cin >> x;
        cin >> y;

        if (z == 'L') {
            long long a = linhas[x];
            long long b = linhas[y];

            linhas[x] = b;
            linhas[y] = a;
        } else {
            long long a = colunas[x];
            long long b = colunas[y];

            colunas[x] = b;
            colunas[y] = a;
        }
    }
    
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            long long linhaAtual = linhas[i];
            long long colunaAtual = colunas[j];

            long long idAtual = ((linhaAtual - 1) * m) + colunaAtual;

            cout << idAtual << (j == m ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}