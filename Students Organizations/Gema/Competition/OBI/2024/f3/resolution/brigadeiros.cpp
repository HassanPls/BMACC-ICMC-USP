#include <bits/stdc++.h>
using namespace std;

const int MAXN = 301;
const int INF = 1e9 + 10;
const int MAXC = 9 * MAXN;

int dp[2][MAXN][MAXC];
int qtd[MAXN];
bool amigo[MAXN];
vector<int> grupo;
int n, k, t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int x;
    cin >> n >> k >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> qtd[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 1) {
            amigo[i] = true;
            grupo.push_back(i);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int b = 0; b <= k; b++) {
            for (int c = 0; c < MAXC; c++) {
                if ((i == 0 || b == 0) && c == 0) {
                    dp[i][b][c] = 0;
                } else {
                    dp[i][b][c] = INF;
                }
            }
        }
    }
    
    for (int a = 1; a <= n; a++) {
        int i = a%2;
        for (int b = 1; b <= k; b++) {
            for (int c = 0; c < MAXC; c++) {
                if (qtd[a] <= c) {
                    dp[i][b][c] = min(
                        dp[i][b][c], 
                        dp[1 - i][b - 1][c - qtd[a]] + abs(a - grupo[b - 1])
                    );
                }
                dp[i][b][c] = min(dp[i][b][c], dp[1 - i][b][c]);
            }
        }
    }
    for (int l = MAXC - 1; l >= 0; l--)
    {
        if (dp[n % 2][k][l] <= t) {
            cout << l << endl;
            return 0;
        }
    }

    return 0;
}