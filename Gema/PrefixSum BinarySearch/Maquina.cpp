#include <bits/stdc++.h>
using namespace std;

long long checkAllTimes(vector<long long> times, long long mid, long long t) {
    long long total = 0;

    for (long long i = 0; i < times.size(); i++)
    {
        total += mid / times[i];

        if (total >= t) return total;
    }
    
    return total;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t;
    cin >> n >> t;
    vector<long long> times(n);
    long long min_k = 1e18;
    long long minT = 1, maxT = 1;

    for (long long i = 0; i < n; i++)
    {
        cin >> times[i];
        min_k = min(min_k, times[i]);
    }

    maxT = min_k * t;
    long long result = 0;

    while(minT <= maxT) {
        long long mid = minT + (maxT - minT)/2;

        if (checkAllTimes(times, mid, t) >= t) {
            result = mid;
            maxT = mid - 1;
        } else {
            minT = mid + 1;
        }
    }
    
    cout << result;

    return 0;
}