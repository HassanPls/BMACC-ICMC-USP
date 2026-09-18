#include <bits/stdc++.h>
using namespace std;

long long numsOfSubArray(vector<long long>& nums, long long mid) {
    long long total = 0;
    

    long long curTotal = 0;
    for (long long i = 0; i < nums.size(); i++)
    {
        
        if (nums[i] > mid) return 1e9;

        if (nums[i] + curTotal > mid) {
            curTotal = nums[i];
            total++;
        } else {
            curTotal += nums[i];
        }
    }
    
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,k;
    cin >> n >> k;

    vector<long long> nums(n);

    long long low = 1;
    long long high = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
        high += nums[i];
    }
    
    long long result = 1;

    while (high >= low)
    {
        long long mid = low + (high - low)/2;

        if (numsOfSubArray(nums, mid) < k) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    

    cout << result;

    return 0;
}