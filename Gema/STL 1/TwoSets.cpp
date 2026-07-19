#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int somatotal = n * (n+1) / 2;

    if (somatotal % 2 != 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    vector<int> g1, g2;

    if (n%4 == 0) {
        for (size_t i = 1; i <= n; i+=4)
        {
            g1.push_back(i);
            g1.push_back(i+3);

            g2.push_back(i+1);
            g2.push_back(i+2);
        }
    } else {
        g1.push_back(1);
        g1.push_back(2);
        g2.push_back(3);

        for (size_t i = 4; i <= n; i+=4)
        {
            g1.push_back(i);
            g1.push_back(i+3);

            g2.push_back(i+1);
            g2.push_back(i+2);
        }
    }

    cout << g1.size() << "\n";
    for (int a : g1)
    {
        cout << a << " ";
    }
    cout << "\n";

    cout << g2.size() << "\n";
    for (int a : g2)
    {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}

/* 1

1 2

1 2 3 - SIM
1 2
3

1 2 3 4 - SIM
1 4
2 3

1 2 3 4 5 - NO

1 2 3 4 5 6 - NO

1 2 3 4 5 6 7 - SIM
1 2 4 7
3 5 6

1 2 3 4 5 6 7 8 - SIM
1 4 5 8
2 3 6 7 */

