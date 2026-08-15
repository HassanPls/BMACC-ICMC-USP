#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> habilities(n);

    for (int i = 0; i < n; i++)
    {
        cin >> habilities[i];
    }

    sort(habilities.begin(), habilities.end());

    int i = 0, result = 0;

    for (int j = 0; j < n; j++)
    {
        while (habilities[j] - habilities[i] > 5)
        {
            i++;
        }
        
        result = max(result, j - i + 1);
    }
    
    cout << result;

    return 0;
}