#include <bits/stdc++.h>
using namespace std;

int Hanoi(int n) {
    if (n == 1) return 1;
    return (Hanoi(n-1) * 2) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 1;
    int n = -1;

    while (cin >> n && n != 0)
    {
        cout << "Teste " << i << "\n";
        cout << Hanoi(n) << "\n";
        i++;
    }

    return 0;
}