#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long maior = -1;
    long long n = -1;

    while (n != 0)
    {
        cin >> n;
        maior = max(n, maior);
    }
    
    cout << maior;

    return 0;
}