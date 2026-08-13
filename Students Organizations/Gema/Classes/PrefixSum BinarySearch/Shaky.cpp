#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long mid, vector<long long> &boxes, long long k) {
    if (mid == 0) return true;

    long long alunos = 0;

    for(long long doces : boxes) {
        alunos += (doces/mid);
    }

    return alunos >= k;
}

void solve() {

    long long n, k;
    cin >> n >> k;
    vector<long long> boxes(n);
    long long max_candies = 0;

    for (long long i = 0; i < n; i++)
    {
        cin >> boxes[i];
        max_candies = max(max_candies, boxes[i]);
    }

    long long low = 1, high = max_candies;
    long long ans = 0;

    while (low <= max_candies)
    {
        long long mid = low + (high-low) / 2;

        if (isPossible(mid, boxes, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    

    cout << ans << "\n";
    

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