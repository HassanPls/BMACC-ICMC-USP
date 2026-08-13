#include <bits/stdc++.h>
using namespace std;

int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n-1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << fatorial(n);

    return 0;
}