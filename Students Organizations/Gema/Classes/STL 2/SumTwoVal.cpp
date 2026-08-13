#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    map<int, int> sum;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (sum.count(num)) {
            cout << sum[num]+1 << " " << i+1;
            return 0;
        } else {
            sum[x - num] = i;
        }
    }
    
    cout << "IMPOSSIBLE";

    return 0;
}