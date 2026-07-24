#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> playlist;
    int maxSize = 1, inicio = 0;

    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;

        if (playlist.count(id) && playlist[id] >= inicio) { 
            inicio = playlist[id] + 1;
        } 

        playlist[id] = i;

        maxSize = max(maxSize, (i - inicio + 1));
    }
    

    return 0;
}