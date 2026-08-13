#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n/2; i++)
    {
        int x, y;
        cin >> x >> y;
        
        pq.push(x);
        pq.push(y);

        pq.pop();
    }

    long long total = 0;
    while(!pq.empty()) {
        total += pq.top();
        pq.pop();
    }
    
    cout << total;

    return 0;
}