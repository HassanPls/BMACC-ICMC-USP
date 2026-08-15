#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    
    long long i = 1, result = 0;

    for (int j = 1; j < n; j++)
    {
        if (nums[j] == nums[j - 1]) {
            i++;
        } else {
            result += (i * (i + 1))/2;
            i = 1;
        }
    }
    
    result += (i * (i + 1))/2;

    cout << result;

    return 0;
}