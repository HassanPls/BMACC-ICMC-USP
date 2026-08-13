#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long total = 0, c = 0, t = 0;
    cin >> c >> t;

    vector<long long> circulosRaio(c);

    for (int i = 0; i < c; i++)
    {
        cin >> circulosRaio[i];
    }

    for (int i = 0; i < t; i++)
    {
        long long x, y;
        cin >> x >> y;
        double dist = sqrt((x*x) + (y*y));
        auto it = lower_bound(circulosRaio.begin(), circulosRaio.end(), dist);

        total += (circulosRaio.end() - it);
    }

    cout << total << "\n";

    return 0;
}