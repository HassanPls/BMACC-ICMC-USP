#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (size_t i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        tickets.insert(price);
    }
    
    for (size_t i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        auto it = tickets.upper_bound(t);

        if (it == tickets.begin()) {
            cout << -1 << "\n";
        } else {
            it--;
            cout << *it << "\n";

            tickets.erase(it);
        }
    }

    return 0;
}