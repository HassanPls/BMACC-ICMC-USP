#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> semaforos;
    multiset<int> dist;

    int x, n;
    cin >> x >> n;

    semaforos.insert(0);
    semaforos.insert(x);
    dist.insert(x);

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        auto itSemaforoDir = semaforos.upper_bound(p);
        auto itSemaforoEsq = itSemaforoDir;
        itSemaforoEsq--;

        int semaforoDir = *itSemaforoDir;
        int semaforoEsq = *itSemaforoEsq;

        int distEsq = p - semaforoEsq;
        int distDir = semaforoDir - p;

        dist.insert(distEsq);
        dist.insert(distDir);
        dist.erase(dist.find(semaforoDir - semaforoEsq));

        semaforos.insert(p);

        cout << *dist.rbegin() << " ";
    }
    

    return 0;
}