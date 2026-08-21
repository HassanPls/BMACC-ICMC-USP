#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, d, t;
    cin >> c >> d >> t;

    double litroNeeded = d/c;
    double litroEncher = litroNeeded - t;

    if (litroEncher <= 0) {
        cout << 0.0;
    } else {
        double litroEncher = ceil(litroEncher * 10.0)/10.0;

        //printf("%.1f", litroEncher);
        cout << fixed << setprecision(1) << litroEncher;
    }

    return 0;
}