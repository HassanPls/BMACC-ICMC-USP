#include <bits/stdc++.h>
using namespace std;

long long calcMoedas(vector<long long>& capsulas, long long dias) {
    long long total = 0;
    for (long long i = 0; i < capsulas.size(); i++)
    {
        long long moedas = dias/capsulas[i];
        total += moedas;
    }
    
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, f;
    cin >> n >> f;

    vector<long long> capsulas(n);
    for (long long i = 0; i < n; i++) cin >> capsulas[i];
    
    long long min = 0, max = 1e8;
    long long result = 0;

    while (min <= max)
    {
        long long mid = min + (max-min)/2;
        long long moedas = calcMoedas(capsulas, mid);

        if (moedas >= f) {
            max = mid - 1;
            result = mid;
        } else if (moedas < f) {
            min = mid + 1;
        } 
    }
    
    cout << result;

    return 0;
}