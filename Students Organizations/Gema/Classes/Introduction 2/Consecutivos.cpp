#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;

    int first = 0;
    cin >> first;

    int total = 1;
    int totalMaior = 1;

    for (int i = 1; i < n; i++)
    {
        int atual = 0;
        cin >> atual;

        if (atual == first)
        {
            total++;
            totalMaior = max(totalMaior, total);
        }
        else
        {
            total = 1;
            totalMaior = max(totalMaior, total);
        }

        first = atual;
    }

    cout << totalMaior;

    return 0;
}