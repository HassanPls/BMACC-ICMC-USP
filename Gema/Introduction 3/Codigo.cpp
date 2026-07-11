#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, total = 0;
    cin >> n;
    vector<int> nums(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (size_t i = 0; i < n - 2; i++)
    {
        if (nums[i] == 1 && nums[i+1] == 0 && nums[i+2] == 0) {
            total++;
        }
    }
    
    cout << total;

    return 0;
}