#include <bits/stdc++.h>
using namespace std;

long long solve() {

    int n;
    cin >> n;

    long long pontuacao = 0;
    vector<long long> a(n);
    vector<long long> b(n);
    vector<pair<long long, long long>> points(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        pair<long long, long long> comparison;
        comparison.first = a[i] + b[i];
        comparison.second = i;
        points[i] = comparison;
    }

    sort(points.rbegin(), points.rend());

    long long index = 0;
    for (auto pair : points)
    {
        long long indice = pair.second;

        if (index%2==0) {
            pontuacao += a[indice] - 1;
        } else {
            pontuacao -= b[indice] - 1;
        }
        index++;
    }

    return pontuacao;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << solve() << "\n";
    }

    return 0;
}