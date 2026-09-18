#include <bits/stdc++.h>
using namespace std;

int isPossible(int mid, vector<int>& pages) {
    int total = 1;
    int curTotal = 0;
    for (int i = 0; i < pages.size(); i++)
    {
        if (pages[i] > mid) return 1e9;

        if (curTotal + pages[i] <= mid) {
            curTotal += pages[i];
        } else {
            curTotal = pages[i];
            total++;
        }
    }
    
    return total;
}

int solve() {
    int m, k;
    cin >> m >> k;
    vector<int> pages(m);
    int high = 0;
    int low = 0;
    for (int i = 0; i < m; i++) {
        cin >> pages[i];
        high += pages[i];
        low = max(low, pages[i]);
    }

    int result = high;
    while (high >= low)
    {
        int mid = low + (high - low)/2;

        if (isPossible(mid, pages) <= k) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    vector<string> tokens;
    int cur_total = 0;
    int scribes_left = k;

    for (int i = m-1; i >= 0; i--)
    {
        if (pages[i] + cur_total > result || i + 1 < scribes_left) {
            tokens.push_back("/");
            scribes_left--;
            cur_total = 0;
        }

        tokens.push_back(to_string(pages[i]));
        cur_total += pages[i];
        
    }
    
    reverse(tokens.begin(), tokens.end());

    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}