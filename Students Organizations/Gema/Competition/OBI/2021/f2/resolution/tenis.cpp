#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums(4);

    for (int i = 0; i < 4; i++) cin >> nums[i];
    
    sort(nums.begin(), nums.end());

    int timeA = nums[0] + nums[3];
    int timeB = nums[1] + nums[2];

    cout << abs(timeA - timeB);

    return 0;
}