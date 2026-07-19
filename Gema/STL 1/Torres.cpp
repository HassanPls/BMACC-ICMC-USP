#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multiset<int> torres;

    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int cube;
        cin >> cube;

        auto it = torres.upper_bound(cube);

        if (it != torres.end())
        {
            torres.erase(it);
        }
        
        torres.insert(cube);
    }

    cout << torres.size();

    return 0;
}