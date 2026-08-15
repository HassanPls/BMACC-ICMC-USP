#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> times(n);

    for (int i = 0; i < n; i++)
    {
        cin >> times[i].second >> times[i].first;
    }

    sort(times.begin(), times.end());
    
    int timeNow = 0;
    int maiorAtraso = 0;

    for (int i = 0; i < n; i++)
    {
        timeNow += times[i].second;

        int atraso = max(0, timeNow - times[i].first);
        maiorAtraso = max(maiorAtraso, atraso);
    }
    
    cout << maiorAtraso;

    return 0;
}