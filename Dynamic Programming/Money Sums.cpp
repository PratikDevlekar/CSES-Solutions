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
    // beginner intuition

    /*
    int n; cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    set<int> ans;
    sort(all(val));
    ans.insert(val[0]);
    for (int i = 1; i < n; i++) {
        set<int>tmp;
        tmp.insert(val[i]);
        for (auto x : ans) {
            tmp.insert(val[i] + x);
        }
        for (auto x : tmp) ans.insert(x);
        tmp.clear();
    }
    cout << ans.size() << endl;;
    for (auto x : ans) cout << x << " ";
    */

    //Also solved using 0/1 knapsack

    /*
    int n; cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    vector<vector<bool>> dp(n + 1, vector<bool> (1e5 + 1, false));
    int cnt = 0;
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 1e5; j++) {
            if (j - val[i - 1] >= 0) {
                if (dp[i - 1][j] == true || dp[i - 1][j - val[i - 1]] == true) {
                    dp[i][j] = true;
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
            if (i == n) {
                if (dp[n][j] == true) cnt++;
            }
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= 1e5; i++) {
        if (dp[n][i] == true) cout << i << " ";
    }
    */

    //Slightly more optimized way of doing it

    int n, tot = 0; cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        tot += val[i];
    }
    vector<bool> dp(tot + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = tot; j >= 0; j--) {
            if (j - val[i] >= 0) {
                if (dp[j] == true || dp[j - val[i]] == true)
                    dp[j] = true;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= tot; i++) {
        if (dp[i] == true) ans.pb(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
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
