#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<long long> freq(256, 0);
    freq[0] = 1;

    int current_mask = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int bit = s[i] - 'a';
        current_mask ^= (1 << bit);

        ans += freq[current_mask];

        for (int j = 0; j < 8; j++)
        {
            int target_mask = current_mask ^ (1 << j);
            ans += freq[target_mask];
        }

        freq[current_mask]++;
        
    }
    
    cout << ans << endl;

    return 0;
}