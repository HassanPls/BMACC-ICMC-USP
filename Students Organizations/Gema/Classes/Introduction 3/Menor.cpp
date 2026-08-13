#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;

    vector<int> X(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    int menor = X[0], indice = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (X[i] < menor) {
            menor = X[i];
            indice = i;
        }
    }
    
    cout << "Menor valor: " << menor << "\n";
    cout << "Posicao: " << indice << "\n";

    return 0;
}