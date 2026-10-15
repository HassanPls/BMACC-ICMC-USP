#include <bits/stdc++.h>
using namespace std;

struct Silaba {
    long long a;
    long long b;
    long long id;
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n, k;cin >> n >> k;
    vector<Silaba> silabas(n);

    for (int i = 0; i < n; i++) {
        silabas[i].id = i;
        cin >> silabas[i].a;
    }
    for (int i = 0; i < n; i++) cin >> silabas[i].b;

    vector<pair<long long, long long>> por_b(n);
    for (int i = 0; i < n; i++) por_b[i] = {silabas[i].a >= silabas[i].b ? silabas[i].b : silabas[i].a, silabas[i].id};
    sort(por_b.rbegin(), por_b.rend());
    
    vector<bool> zerado(n, false);
    for (int i = 0; i < min(n,k); i++) zerado[por_b[i].second] = true;
    
    long long soma_delta_positos = 0;
    long long max_b_usado = 0;

    for (int i = 0; i < n; i++)
    {
        if (zerado[i]) soma_delta_positos += silabas[i].a;
        else {
            if (silabas[i].a >= silabas[i].b) {
                soma_delta_positos += (silabas[i].a - silabas[i].b);
                max_b_usado = max(max_b_usado, silabas[i].b);
            }
        }
    } 
    
    long long resposta = soma_delta_positos + max_b_usado;
    
    for (int i = 0; i < n; i++)
    {
        if (!zerado[i] && silabas[i].a < silabas[i].b) resposta = max(resposta, soma_delta_positos + silabas[i].a);
    }
    
    cout << resposta;return 0;
}