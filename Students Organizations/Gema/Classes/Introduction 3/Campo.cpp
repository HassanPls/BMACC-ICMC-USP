#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    vector<int> minas(n), result(n);

    for (int i = 0; i < n; i++)
    {
        cin >> minas[i];
    }
    
    result[0] = minas[0] + minas[1];
    result[n-1] = minas[n-1] + minas[n-2];
    
    for (int i = 1; i < n-1; i++)
    {
        result[i] = minas[i - 1] + minas[i] + minas[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}