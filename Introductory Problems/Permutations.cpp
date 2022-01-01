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
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return;
    }
    if (n == 1) {
        cout << 1 << " ";
        return;
    }
    vector<int> v, c;
    int mid = (n / 2) + 1;
    for (int i = 0; i < mid; i++) {
        v.push_back(i + 1);
    }
    int f = 0;
    for (int i = mid; i < n; i++) {
        if (n % 2 == 0 && f == 0) {
            c.push_back(i);
            f = 1;
        }
        c.push_back(i + 1);
    }
    if (n % 2 != 0) {
        int l = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                cout << v[l++] << " ";
            else
                cout << c[k++] << " ";
        }
    }
    else {
        v.pop_back();
        reverse(v.begin(), v.end());
        reverse(c.begin(), c.end());
        int l = 0, k = 0;
        // for (auto x : c) cout << x;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                cout << v[l++] << " ";
            else
                cout << c[k++] << " ";
        }
    }
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
