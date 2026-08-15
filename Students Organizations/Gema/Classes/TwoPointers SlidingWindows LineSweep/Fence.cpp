#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> heights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    long long lower = 0;
    long long total = 0;
    long long index = 1;

    for (int i = 0; i < k; i++)
    {
        total += heights[i];
    }
    
    lower = total;

    for (int i = 1; i < n-k+1; i++)
    {
        total -= heights[i-1];
        total += heights[i+k-1];

        if (total < lower) {
            lower = min(lower, total);
            index = i+1;
        }
    }

    cout << index;
    
    return 0;
}