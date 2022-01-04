#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    auto check = [&](int s, int e) -> int {
        // a[s] = fst + dif * (s - 1)
        pair<int, int> dif = make_pair(a[e] - a[s], e - s);
        pair<int, int> fst = make_pair(a[s] * (e - s) - (s - 1) * dif.first, e - s);
        int ret = n;
        for (int i = 1; i <= n; i++) {
            // fst + (i - 1) * dif
            pair<int, int> cur = make_pair(fst.first + (i - 1) * dif.first, e - s);
            if (cur.first == cur.second * a[i]) {
                ret--;
            }
        }
        return ret;
    };
    int ans = n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = min(ans, check(i, j));
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}