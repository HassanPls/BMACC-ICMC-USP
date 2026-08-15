#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end()); // O(N log N)

    long long result = -1; 
    
    for (long long i = 0; i < n; i++) // O(N)
    {
        if (nums[i] == k) {
            result = i;
            break;
        }
    }
    
    cout << result;

    return 0;
}