#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    sort(a.begin(), a.end());
    long long G = 0;
    for (int i = 1; i < n; i++) {
        G = __gcd(G, a[i] - a[i - 1]);
    }
    vector<long long> b = a;
    b.emplace_back(a[n - 1] + G);
    vector<long long> c = a;
    long long val = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == val) {
            val -= G;
        } else {
            break;
        }
    }
    c.emplace_back(val);

    auto getOp = [&](vector<long long>& v) {
        sort(v.begin(), v.end());
        int m = (int) v.size();
        long long ret = 0;
        for (int i = 0; i < m; i++) {
            ret += (v[m - 1] - v[i]) / G;
        }
        return ret;
    };

    cout << min(getOp(b), getOp(c)) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}