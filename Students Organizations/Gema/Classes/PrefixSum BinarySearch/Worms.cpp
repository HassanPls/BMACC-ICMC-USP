#include <bits/stdc++.h>
using namespace std;

int bs(vector<int>& pile, int target) {
    auto it = lower_bound(pile.begin(), pile.end(), target);
    return it - pile.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> pile(n);
    cin >> pile[0];
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        pile[i] = pile[i-1] + x;
    }

    cin >> m;
    vector<int> labels(m);
    for (int i = 0; i < m; i++) cin >> labels[i];
    
    for (int i = 0; i < m; i++)
    {
        cout << bs(pile, labels[i]) + 1 << "\n";
    }
    

    return 0;
}