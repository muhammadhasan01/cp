#include <bits/stdc++.h>

using namespace std;

const long long MAX = 2e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long mul = 1;
    bool isMulBig = false;
    for (int i = 1; i <= n; i++) {
        if (mul > MAX / a[i]) {
            isMulBig = true;
            break;
        }
        mul *= a[i];
    }
    if (isMulBig) {
        int l = n, r = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] > 1) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        if (l > r) {
            l = 1, r = 1;
        }
        cout << l << ' ' << r << '\n';
        return;
    }
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 1) {
            pos.emplace_back(i);
        }
    }
    vector<long long> sum(n + 1);
    vector<long long> pre(n + 1);
    pre[0] = 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] * a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    tuple<long long, int, int> mx = make_tuple(0LL, 1, 1);
    int len = (int) pos.size();
    for (int i = 0; i + 1 < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int l = pos[i], r = pos[j];
            long long val = pre[r] / pre[l - 1] - (sum[r] - sum[l - 1]);
            mx = max(mx, make_tuple(val, l, r));
        }
    }
    auto [_, l, r] = mx;
    cout << l << ' ' << r << '\n';
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