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
// int mod = 1e9 + 7;

int position(vector<int> tail, int k) {
    int l = 0, r = tail.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (tail[mid] >= k) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return r;
}

void LIS(vector<int> val, int n) {
    vector<int> tail;
    tail.pb(val[0]);
    for (int i = 1; i < n; i++) {
        if (val[i] > tail[tail.size() - 1]) {
            tail.pb(val[i]);
        }
        else {
            int pos = position(tail, val[i]);
            tail[pos] = val[i];
        }
    }
    cout << tail.size();
}

void solve() {
    int n; cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    LIS(val, n);
}

signed main() {
    auto start = high_resolution_clock::now();
    IOS;
    // sieve(1000);
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
