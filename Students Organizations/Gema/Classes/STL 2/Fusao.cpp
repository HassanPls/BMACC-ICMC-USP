#include <bits/stdc++.h>
using namespace std;

int solve() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> sets(n);
    vector<int> numsFreq(m + 1, 0);
    set<int> total;

    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;

        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            sets[i].push_back(x);
            total.insert(x);
            numsFreq[x]++;
        }
    }

    if (total.size() < m) {
        cout << "NO\n";
        return 0;
    }

    int opcionais = 0;

    for (int i = 0; i < n; i++)
    {
        int isOptional = true;

        for (int num : sets[i])
        {
            if (numsFreq[num] < 2) {
                isOptional = false;
            }
        }
        
        if (isOptional) opcionais++;
    }

    if (opcionais >= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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