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
vector<int> val(5000);
vector<vector<int>> dp(5000 + 1, vector<int>(5000 + 1, -1));
int cal(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    if (l == r) {return dp[l][r] = val[l];}
    if (l + 1 == r) {return  dp[l][r] = max(val[l], val[r]);}
    return  dp[l][r] = max(val[l] + min(cal(l + 1, r - 1), cal(l + 2, r)), val[r] + min(cal(l + 1, r - 1), cal(l, r - 2)));
}


void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << cal(0, n - 1);
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
