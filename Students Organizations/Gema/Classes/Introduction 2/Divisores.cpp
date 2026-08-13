#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n = 0;
    cin >> n;

    for (long long i = 1; i <= n; i++)
    {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    
    return 0;
}