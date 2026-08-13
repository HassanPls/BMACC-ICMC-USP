#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t = 0;
    cin >> t;
    vector<int> comandos(t);

    for (long long i = 0; i < t; i++)
    {
        cin >> comandos[i];
    }

    int a = 0, b = 0;

    for (long long i = 0; i < t; i++)
    {
        if (comandos[i] == 1)
        {
            if (a)
            {
                a--;
            }
            else
            {
                a++;
            }
        }
        else
        {
            if (a)
            {
                a--;
            }
            else
            {
                a++;
            }

            if (b)
            {
                b--;
            }
            else
            {
                b++;
            }
        }
    }

    cout << a << "\n"
         << b;

    return 0;
}