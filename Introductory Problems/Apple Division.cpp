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
    int n; cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    int ans = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) sum1 += val[j];
            else sum2 += val[j];
        }
        ans = min(ans, abs(sum2 - sum1));
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
