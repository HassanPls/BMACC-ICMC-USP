#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    cout << "N[0] = " << n << "\n";
    for (size_t i = 1; i < 10; i++)
    {
        n = n * 2;
        printf("N[%d] = %d\n", i, n);
    }
    
    return 0;
}