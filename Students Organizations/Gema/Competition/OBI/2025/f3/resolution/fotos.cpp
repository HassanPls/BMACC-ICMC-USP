#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    vector<int> arr(n);
    for (long long i = 0; i < n; i++) cin >> arr[i];
    
    long long j = 0;
    long long count = 0;
    long long pos_um = -1;
    long long result = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1) {
            count += arr[i];
            pos_um = i;
        }

        while (count > 1)
        {
            count -= arr[j];
            j++;
        }
        
        if (count == 1) {
            result += (pos_um - j + 1);
        }
    }
    
    cout << result;

    return 0;
}