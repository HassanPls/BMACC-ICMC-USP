#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x;
    cin >> n >> x;

    map<long long, int> prefix;
    prefix[0] = 1;
    
    long long total = 0;
    long long current_sum = 0;

    for (long long i = 0; i < n; i++)
    {
        long long a_i;
        cin >> a_i;

        current_sum += a_i;

        if (prefix.count(current_sum - x)) {
            total += prefix[current_sum - x];
        }

        prefix[current_sum]++;
    }

    cout << total;

    return 0;
}