#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << min({(i - 0), (n - i + 1), (j - 0), (n - j + 1)});
        }
        cout << endl;
        
    }
    
    return 0;
}