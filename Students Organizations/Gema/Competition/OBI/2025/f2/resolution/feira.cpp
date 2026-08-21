#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    vector<int> tipo(n + 1);
    vector<long long> preco(n + 1);

    for (long i = 1; i < n + 1; i++) cin >> tipo[i];
    for (long i = 1; i < n + 1; i++) cin >> preco[i];
    
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq_global;
    vector<priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>> pq_tipo(t+1);
    vector<bool> vendido(n+1, false);

    for (int i = 1; i < n+1; i++)
    {
        pq_global.push({preco[i], tipo[i], i});
        pq_tipo[tipo[i]].push({preco[i], i});
    }
    
    long long lucroTotal = 0;
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int u;
        cin >> u;

        if (u > 0) {
            while (!pq_tipo[u].empty() && vendido[pq_tipo[u].top().second])
            {
                pq_tipo[u].pop();
            }

            if (!pq_tipo[u].empty()) {
                long long pr = pq_tipo[u].top().first;
                long long id = pq_tipo[u].top().second;

                pq_tipo[u].pop();
                vendido[id] = true;
                lucroTotal += pr;
            }
            
        } else {

            while (!pq_global.empty())
            {
                long long pr = get<0>(pq_global.top());
                long long tp = get<1>(pq_global.top());
                long long id = get<2>(pq_global.top());

                if (!vendido[id]) break;

                pq_global.pop();
            }

            if (!pq_global.empty()) {
                long long pr = get<0>(pq_global.top());
                long long tp = get<1>(pq_global.top());
                long long id = get<2>(pq_global.top());

                pq_global.pop();
                vendido[id] = true;
                lucroTotal += pr;
            }
        }
    }
    
    cout << lucroTotal;

    return 0;
}