#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q;
    cin >> n >> q;
    vector<long long> nums(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<long long> prefix(n+1);
    prefix[0] = 0;

    for (long long i = 1; i < n+1; i++)
    {
        prefix[i] = nums[i-1] + prefix[i-1];
    }
    

    for (long long i = 0; i < q; i++)
    {
        long long q1, q2;
        cin >> q1 >> q2;
        cout << prefix[q2] - prefix[q1-1] << "\n";
    }

    return 0;
}