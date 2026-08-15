#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<long long, int>> schedule;

    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        schedule.push_back({x, 1});
        schedule.push_back({y, -1});
    }

    sort(schedule.begin(), schedule.end());
    int people = 0, maxP = 0;

    for (long long i = 0; i < 2 * n; i++)
    {
        people += schedule[i].second;
        maxP = max(maxP, people);
    }
    
    cout << maxP;

    return 0;
}