#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    int max_h = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_h = max(max_h, a[i]);
    }
    
    int fases = 0;

    while (true)
    {
        int min_h = max_h;
        for (int i = 0; i < n; i++)
        {
            min_h = min(min_h, a[i]);
        }
        
        if (min_h == max_h) break;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == min_h) {
                int j = i;

                while (a[j] == min_h)
                {
                    a[j]++;
                    j++;
                }
                
                fases++;
                i = j - 1;
            }
        }
    }

    cout << fases << "\n";

    return 0;
}