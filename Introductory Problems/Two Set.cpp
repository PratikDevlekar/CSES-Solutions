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
    int n; cin >> n;
    int sum = ((n + 1) * n) / 2;
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    sum = sum / 2;
    bool tmp[n + 1];
    int cnt = 0;
    memset(tmp, false, sizeof(tmp));
    for (int i = n; i >= 1; i--) {
        if (sum - i >= 0) {
            tmp[i] = true;
            cnt++;
            sum = sum - i;
        }
    }
    cout << cnt << endl;;
    for (int i = 0; i <= n; i++) {
        if (tmp[i] == true) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << n - cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (tmp[i] == false) {
            cout << i << " ";
        }
    }
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
