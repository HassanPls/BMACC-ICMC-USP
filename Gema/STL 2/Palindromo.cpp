#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    map<char, int> characters;

    for (size_t i = 0; i < s.size(); i++)
    {
        characters[s[i]]++;
    }

    int hasOdd = 0;
    char charMeio = ' ';

    for (auto c : characters)
    {
        if (c.second % 2 != 0)
        {
            hasOdd++;
            charMeio = c.first;
        }
    }

    string result = "";

    if (hasOdd > 1)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        for (auto c : characters)
        {
            result.append(c.second / 2, c.first);
        }

        string reversedString = result;
        reverse(reversedString.begin(), reversedString.end());

        if (s.size() % 2 == 0)
        {
            if (hasOdd > 0)
            {
                cout << "NO SOLUTION";
            }
            else
            {
                cout << result << reversedString;
            }
        }
        else
        {
            cout << result << charMeio << reversedString;
        }
    }

    return 0;
}