#include <bits/stdc++.h>
using namespace std;

long long somatorio(long long A, long long k, long long L) {
    if (k <= 0) return 0;
    if (k > 2e9) return L + 1;

    long long sum = (((2 * A) + k - 1) * k)/2;

    if (sum > L) return L + 1;
    
    return sum;
}

long long solve() {
    long long L, A, B;
    cin >> L >> A >> B;

    long long maxTotal = B - A + 1;
    long long low = 1;
    long long high = maxTotal;
    long long k = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long sum = somatorio(A, mid, L);

        if (sum < L) {
            k = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return min(k + 1, maxTotal);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        cout << solve() << "\n";
    }
    

    return 0;
}