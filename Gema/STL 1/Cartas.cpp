#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    set<int> conjA, conjB, conjT;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        conjA.insert(x);
        conjT.insert(x);
    }

    for (int i = 0; i < b; i++)
    {
        int y;
        cin >> y;
        conjB.insert(y);
        conjT.insert(y);
    }

    int intersection = (conjA.size() + conjB.size()) - conjT.size();
    cout << (min(conjA.size(), conjB.size()) - intersection) << "\n";

    return 0;
}