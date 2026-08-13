#include <bits/stdc++.h>
using namespace std;

int testAllSandwiches(int mid, vector<int> &sandwiches) {
    int total = 0;

    for (int i = 0; i < sandwiches.size(); i++)
    {
        total += sandwiches[i]/mid;
    }
    
    return total;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> sandwiches(k);
    int low = 1, high = 0, mid = 0, result = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> sandwiches[i];
        high = max(high, sandwiches[i]);
    }

    while (low <= high)
    {
        mid = low + (high - low)/2;

        int total = testAllSandwiches(mid, sandwiches);

        if (total >= n) { // se o total for maior, quer dizer q dividiu muito e os cm estão pequenos, então low precisa aumentar
            result = mid;
            low = mid + 1;
        } else { // se não o high precisa diminuir
            high = mid - 1;
        }
    }
    
    cout << result;

    return 0;
}