#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int centena = n/100;
    n = n - (centena * 100);

    int cinquenta = n/50;
    n = n - (cinquenta * 50);

    int vintecinco = n/25;
    n = n - (vintecinco * 25);

    int dezena = n/10;
    n = n - (dezena * 10);

    int cinco = n/5;
    n = n - (cinco * 5);

    int unidade = n/1;
    n = n - (unidade * 1);

    cout << (centena + cinquenta + vintecinco + dezena + cinco + unidade);

    return 0;
}