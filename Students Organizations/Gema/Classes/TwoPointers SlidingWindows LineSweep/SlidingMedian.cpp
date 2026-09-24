#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (long long i = 0; i < n; i++) cin >> nums[i];
    
    priority_queue<long long> lo;
    priority_queue<long long, vector<long long>, greater<long long>> hi;

    unordered_map<long long, int> hashTable;

    for (int i = 0; i < k; i++) lo.push(nums[i]);
    for (int i = 0; i < k/2; i++)
    {
        hi.push(lo.top());
        lo.pop();
    }
    
    int i = k;
    while (true)
    {
        cout << lo.top();

        if (i >= n) break;
        cout << " ";

        long long outNum = nums[i - k];
        long long inNum = nums[i++];
        int balance = 0;

        balance += (outNum <= lo.top()) ? -1 : 1;
        hashTable[outNum]++;

        if (!lo.empty() && inNum <= lo.top()) {
            balance++;
            lo.push(inNum);
        } else {
            balance--;
            hi.push(inNum);
        }

        if (balance < 0) {
            lo.push(hi.top());
            hi.pop();
            balance++;
        }
        if (balance > 0) {
            hi.push(lo.top());
            lo.pop();
            balance--;
        }

        while (!lo.empty() && hashTable[lo.top()]) {
            hashTable[lo.top()]--;
            lo.pop();
        }

        while (!hi.empty() && hashTable[hi.top()]) {
            hashTable[hi.top()]--;
            hi.pop();
        }

    }

    return 0;
}