#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Ia, Ib, Fa, Fb;

    cin >> Ia >> Ib >> Fa >> Fb;

    if (Ia == Fa && Ib == Fb) {
        cout << 0;
    } else if (Ia != Fa && Ib == Fb) {
        cout << 1;
    } else {
        int newIa = !Ia;

        if (newIa == Fa) {
            cout << 1;
        } else {
            cout << 2;
        }
    }

    return 0;
}