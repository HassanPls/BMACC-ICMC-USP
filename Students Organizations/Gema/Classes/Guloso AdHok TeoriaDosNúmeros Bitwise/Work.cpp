#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    int losses = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0) losses++;
    }

    vector<int> folders;
    int lossesNow = 0;
    int tamAtual = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 && lossesNow == 2) {
            lossesNow = 0;
            folders.push_back(tamAtual);
            tamAtual = 0;
        }

        tamAtual++;
        if (a[i] < 0) lossesNow++;
    }

    folders.push_back(tamAtual);
    
    cout << folders.size() << "\n";
    for (int i = 0; i < folders.size(); i++)
    {
        cout << folders[i] << (i + 1 == folders.size() ? "" : " ");
    }
    

    return 0;
}