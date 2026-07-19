#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> result;

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        result.insert(num);
    }
    
    cout << result.size();

    return 0;
}