#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<long long> nums;
    
    for (long long i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end()); // O(N log N)

    long long low = 0, high = n-1, result = 0; 
    
    while (low <= high) // O (log2 N)
    {
        long long mid = low + (high - low)/2;

        if (nums[mid] == k) {
            result = mid;
        } else if (nums[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result;

    return 0;
}