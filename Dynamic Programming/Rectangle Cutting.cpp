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
vector<vector<int>> dp(500 + 1, vector<int>(500 + 1, -1));
int  cal(int n, int m) {
    if (n == m) {
        return 0;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, cal(n - i, m) + cal(i, m) + 1);
    }
    for (int i = 1; i < m; i++) {
        ans = min(ans, cal(n, i) + cal(n, m - i) + 1);
    }
    dp[n][m] = ans;
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    cout << cal(n, m);
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
