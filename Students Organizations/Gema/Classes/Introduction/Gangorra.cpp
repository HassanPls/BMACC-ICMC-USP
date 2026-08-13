#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c1, c2, p1, p2;
    cin >> p1 >> c1 >> p2 >> c2;

    if (c1 * p1 == c2 * p2)
    {
        cout << 0;
    }
    else if (c1 * p1 > c2 * p2)
    {
        cout << -1;
    }
    else
    {
        cout << 1;
    }

    return 0;
}