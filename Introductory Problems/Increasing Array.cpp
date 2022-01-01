#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(v) (v).begin(), (v).end()
#define fl fflush(stdout)


void solve() {
    int n; cin >> n;
    vector<int> val(n);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 1; i < n ; i++) {
        if (val[i] < val[i - 1]) {
            ans += val[i - 1] - val[i];
            val[i] = val[i - 1];
        }
    }
    cout << ans;
}



signed main() {
    auto start = high_resolution_clock::now();
    FAST;
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
