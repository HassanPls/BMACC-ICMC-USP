#include <bits/stdc++.h>
using namespace std;

int expandirCentro(string s, int i, int j, int n) {
    while (i >= 0 && j < n && s[i] == s[j])
    {
        i--;
        j++;
    }
    
    return j - i - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string c;
    cin >> c;

    int maiorTam = 1;

    for (int i = 0; i < n; i++)
    {
        int tamImpar = expandirCentro(c, i, i, n);
        int tamPar = expandirCentro(c, i, i+1, n);

        maiorTam = max({maiorTam, tamImpar, tamPar});
    }
    
    cout << maiorTam;

    return 0;
}