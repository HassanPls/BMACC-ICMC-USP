#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n = 0;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << n / 2;
    }
    else
    {
        long long num = (n + 1)/ 2;
        cout << num * -1;
    }
    return 0;
}