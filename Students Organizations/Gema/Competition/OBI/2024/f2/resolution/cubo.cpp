#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int zeroFaces = (n - 2)*(n - 2)*(n - 2);
    int tresFaces = 8;
    int umaFaces = (n-2)*(n-2) * 6;
    int duasFaces = (n*n*n) - zeroFaces - tresFaces - umaFaces; 

    cout << zeroFaces << "\n";
    cout << umaFaces << "\n";
    cout << duasFaces << "\n";
    cout << tresFaces << "\n";

    return 0;
}