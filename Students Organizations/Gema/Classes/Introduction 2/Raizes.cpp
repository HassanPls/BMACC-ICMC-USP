#include <bits/stdc++.h>
using namespace std; 

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(4);

    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        double x;
        cin >> x;

        cout << sqrt(x) << "\n";
    }

    return 0;
}