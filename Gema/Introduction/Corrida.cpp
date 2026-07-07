#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, danger = 0;
    cin >> n;
    vector<pair<int, int>> coordenadas(n+1);
    for (size_t i = 0; i <= n; i++)
    {
        cin >> coordenadas[i].first >> coordenadas[i].second;
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        if (
            coordenadas[i].first < coordenadas[i + 1].first && 
            coordenadas[i].second == coordenadas[i + 1].second && 
            coordenadas[i + 1].second < coordenadas[i + 2].second && 
            coordenadas[i + 1].first == coordenadas[i + 2].first
        ) danger++;

        if (
            coordenadas[i].first == coordenadas[i + 1].first && 
            coordenadas[i].second > coordenadas[i + 1].second && 
            coordenadas[i + 1].second == coordenadas[i + 2].second && 
            coordenadas[i + 1].first < coordenadas[i + 2].first
        ) danger++;

        if (
            coordenadas[i].first > coordenadas[i + 1].first && 
            coordenadas[i].second == coordenadas[i + 1].second && 
            coordenadas[i + 1].second > coordenadas[i + 2].second && 
            coordenadas[i + 1].first == coordenadas[i + 2].first
        ) danger++;

        if (
            coordenadas[i].first == coordenadas[i + 1].first && 
            coordenadas[i].second < coordenadas[i + 1].second && 
            coordenadas[i + 1].second == coordenadas[i + 2].second && 
            coordenadas[i + 1].first > coordenadas[i + 2].first
        ) danger++;
    }

    cout << danger;
    return 0;
}