#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    int j = 0;
    vector<int> freqNums(100005, 0);
    int maxIntervalo = 0;

    for (int i = 0; i < n; i++)
    {
        freqNums[nums[i]]++;

        while (freqNums[nums[i]] > 1)
        {
            freqNums[nums[j]]--;
            j++;
        }
        
        maxIntervalo = max(maxIntervalo, i - j + 1);
    }
    
    cout << maxIntervalo;

    return 0;
}