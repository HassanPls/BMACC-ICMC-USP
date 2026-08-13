#include <bits/stdc++.h>
using namespace std;

string solve(string S) {
    if (S[0] != '<' || S[S.size() - 1] != '>') return "No";

    for (size_t i = 1; i < S.size() - 1; i++)
    {
        if (S[i] != '=') return "No";
    }

    return "Yes";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S = "";
    cin >> S;

    cout << solve(S);

    return 0;
}