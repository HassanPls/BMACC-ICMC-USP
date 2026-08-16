#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i < n+1; i++)
    {
        q.push(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        int x = q.front();
        q.pop();
        q.push(x);

        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}