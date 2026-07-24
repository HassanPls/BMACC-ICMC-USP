#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<set<string>> teamsResult(t);
    map<int, string> names;
    priority_queue<int> players;
    

    for (int i = 0; i < n; i++)
    {
        string name;
        int hability;

        cin >> name >> hability;

        names[hability] = name;
        players.push(hability);
    }
    

    for (int i = 0; i < n; i++)
    {
        teamsResult[i%t].insert(names[players.top()]);
        players.pop();
    }

    for (int i = 0; i < t; i++)
    {
        cout << "Time " << (i+1) << "\n";
        for (auto playerName : teamsResult[i])
        {
            cout << playerName << "\n";
        }
        cout << "\n";
    }
    
    
    return 0;
}