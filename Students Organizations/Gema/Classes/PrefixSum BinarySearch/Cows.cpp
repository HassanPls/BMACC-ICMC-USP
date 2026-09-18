#include <bits/stdc++.h>
using namespace std;

bool canPlacesCows(vector<int> &stalls, int n, int c, int mid) {
    int count = 1;
    int last_position = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last_position >= mid) {
            count++;
            last_position = stalls[i];
            if (count == c) return true;
        }
    }

    return false;
}

int solve() {
    int n, c;
    cin >> n >> c;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) cin >> stalls[i];

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];

    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low)/2;

        if (canPlacesCows(stalls, n, c, mid)) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << endl;
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