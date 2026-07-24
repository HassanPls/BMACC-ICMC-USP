#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<char> times;
    for (int i = 0; i < 16; i++)
    {
        times.push('A' + i);
    }

    for (int i = 0; i < 15; i++)
    {
        int x, y;
        cin >> x >> y;

        char time1 = times.front();
        times.pop();
        char time2 = times.front();
        times.pop();

        if (x > y) {
            times.push(time1);
        } else {
            times.push(time2);
        }
    }
    
    cout << times.front();

    return 0;
}