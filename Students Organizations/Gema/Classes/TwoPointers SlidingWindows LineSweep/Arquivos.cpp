#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n = 0, b = 0, result = 0;
    cin >> n >> b;
    vector<long long> sizesFiles(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> sizesFiles[i];
    }
    
    sort(sizesFiles.begin(), sizesFiles.end());

    long long i = 0, j = n-1;
    while(i <= j)
    {
        if (sizesFiles[i] + sizesFiles[j] <= b) i++;
        
        j--;
        result++;
    }
    
    cout << result;

    return 0;
}