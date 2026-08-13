#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k = 0;
    cin >> n >> k;
    int i = 0;

    while (i * k <= n)
    {
        i++;
    }
    
    cout << i * k;

    return 0;
}