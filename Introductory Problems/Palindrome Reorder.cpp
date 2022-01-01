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
    map<char, int> alpha;
    int n = s.length();
    string ans = s;
    for (int i = 0; i < n; i++) {
        alpha[s[i]]++;
    }
    int cnt = 0;
    char oddi;
    for (auto x : alpha) {
        if (x.ss % 2 != 0) {
            cnt++;
            oddi = x.ff;
        }
    } int k = 0;
    if (cnt > 1) {
        cout << "NO SOLUTION";
        return;
    }
    else {
        for (auto x : alpha) {
            if (x.ss % 2 == 0) {
                for (int j = 0; j < (x.ss / 2); j++) {
                    ans[k] = x.ff;
                    ans[n - k - 1] = x.ff;
                    k++;
                }
            }
        }
    }
    if (cnt == 1)
        for (int i = 0; i < alpha[oddi]; i++) {
            ans[i + k] = oddi;
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
