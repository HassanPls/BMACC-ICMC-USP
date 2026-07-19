#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    int total = 0;

    set<char> block;
    string response = "";
    for (int j = 0; j < m; j++)
    {

        block.insert(s[j]);
        if (block.size() >= k)
        {
            total++;
            block.clear();
            response += s[j];
        }
    }

    if (total >= n)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
        char lastChar = 'a';

        for (int i = 0; i < k; i++)
        {
            char c = 'a' + i;
            if (block.count(c) == 0) {
                lastChar = c;
                break;
            }
        }
        
        while (response.size() < n)
        {
            response += lastChar;
        }
        
        cout << response << "\n";
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}