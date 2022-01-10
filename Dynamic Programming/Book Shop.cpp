#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    int n, m; cin >> n >> m;
    vector<int> val(n), page(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> page[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= val[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], page[i - 1] + dp[i - 1][j - val[i - 1]]);
            }
        }
    }
    cout << dp[n][m];
}