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
    string s; cin >> s;
    int cnt = 1;
    int n = s.size();
    if (n == 1) {
        cout << 1 << " ";
        return;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1])
            cnt++;
        else
            cnt = 1;
        ans = max(cnt, ans);
    }
    cout << ans;
}
signed main() {
    auto start = high_resolution_clock::now();
    IOS;
    // sieve(1000);
    int t = 1;
    // fac[0] = 1; fac[1] = 1;
    // rep(i, 2, 300005)fac[i] = (fac[i - 1] * i) % hell;
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
