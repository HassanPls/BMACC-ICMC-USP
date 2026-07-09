#include <bits/stdc++.h>
using namespace std;

int solve() {

    int rating = 0;
    cin >> rating;

    if (rating <= 1399) {
        cout << "Division 4" << "\n";
    } else if (rating <= 1599) {
        cout << "Division 3" << "\n";
    } else if (rating <= 1899) {
        cout << "Division 2" << "\n";
    } else {
        cout << "Division 1" << "\n";
    }

    return 0;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    

    return 0;
}