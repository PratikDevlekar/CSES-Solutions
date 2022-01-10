#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(v) (v).begin(), (v).end()
#define fl fflush(stdout)
int mod = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    vector<vector<int>> dp(n, vector<int> (m + 5, 0));
    if (val[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][val[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((val[i] == j && val[i] != 0) || val[i] == 0) {
                (dp[i][j] += dp[i - 1][j]) %= mod;
                (dp[i][j] += dp[i - 1][j - 1]) %= mod;
                (dp[i][j] += dp[i - 1][j + 1]) %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        (ans += dp[n - 1][i]) %= mod;
    }
    cout << ans;
}


signed main() {
    auto start = high_resolution_clock::now();
    IOS;
    int t = 1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    // cin >> t;
    int i = 1;
    while (t--) {
        // cout << "CASE #" << i << ": ";
        solve();
        cout << endl;
        i++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken:" << duration.count() / 1000000.0 << " seconds" << "\n";
    return 0;
}
