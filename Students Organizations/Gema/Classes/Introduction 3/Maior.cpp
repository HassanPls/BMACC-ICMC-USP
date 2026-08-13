#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums(9);
    cin >> nums[0];
    int maior = nums[0];

    for (size_t i = 1; i < 9; i++)
    {
        cin >> nums[i];
        maior = max(maior, nums[i]); 
    }

    for (size_t i = 1; i <= 9; i++)
    {
        cout << ((nums[i-1]==maior) ? -1 : nums[i-1]) << " ";
        if (i%3==0) cout << "\n";
    }

    return 0;
}