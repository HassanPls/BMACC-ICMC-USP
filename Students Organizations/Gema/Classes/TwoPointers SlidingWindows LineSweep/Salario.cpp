#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, d;
    cin >> n >> d;
    vector<pair<long long, long long>> friends(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> friends[i].first >> friends[i].second;
    }
    
    sort(friends.begin(), friends.end());

    long long i = 0, bestFriendShip = 0, totalFriendship = 0;
    for (long long j = 0; j < n; j++)
    {
        totalFriendship += friends[j].second;

        while (friends[j].first - friends[i].first >= d)
        {
            totalFriendship -= friends[i].second;
            i++;
        }
        
        bestFriendShip = max(bestFriendShip, totalFriendship);
    }
    
    cout << bestFriendShip << endl;

    return 0;
}