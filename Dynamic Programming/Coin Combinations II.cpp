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

void solve() {
    int mod = 1e9 + 7;

    int n, k; cin >> n >> k;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];

    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - val[i] >= 0) {
                dp[j] = (dp[j] % mod + dp[j - val[i]] % mod) % mod;
            }
        }
    }
    cout << dp[k];

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
