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
vector<vector<int>> dp(1e6 + 1, vector<int> (2, 0));

void solve() {
    int n; cin >> n;
    dp[1][0] = 1, dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (dp[i][0] == 0 || dp[i][1] == 0) {
            dp[i][0] = (2 * dp[i - 1][0]) % mod + (dp[i - 1][1]) % mod;
            (dp[i][1] = 4 * dp[i - 1][1] + dp[i - 1][0]) %= mod;
        }
    }
    cout << (dp[n][0] % mod + dp[n][1] % mod) % mod;
}

signed main() {
    auto start = high_resolution_clock::now();
    IOS;
    int t = 1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> t;
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
