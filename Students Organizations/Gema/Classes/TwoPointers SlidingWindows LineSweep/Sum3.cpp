#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x;
    cin >> n >> x;
    vector<pair<long long, long long>> nums(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    
    sort(nums.begin(), nums.end());

    long long iFix = 0;
    while (iFix < n - 2)
    {
        long long target = x - nums[iFix].first;
        long long i = iFix + 1;
        long long j = n - 1;

        while (i < j) {
            long long sum = nums[i].first + nums[j].first;

            if (sum == target) {
                cout << (nums[iFix].second+1) << " " << (nums[i].second+1) << " " << (nums[j].second+1) << " ";
                return 0;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        iFix++;
    }
    
    cout << "IMPOSSIBLE";

    return 0;
}