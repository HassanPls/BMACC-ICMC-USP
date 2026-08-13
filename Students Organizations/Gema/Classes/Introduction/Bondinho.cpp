#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 0, m = 0;
    cin >> a >> m;

    if (a + m <= 50) {
        cout << "S";
    } else {
        cout << "N";
    }

    return 0;
}