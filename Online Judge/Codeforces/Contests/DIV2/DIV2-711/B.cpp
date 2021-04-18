#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, w;

void solve() {
    cin >> n >> w;
    multiset<int> ms;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    int ans = 1, val = w;
    while (!ms.empty()) {
        auto it = ms.upper_bound(val);
        if (it != ms.begin()) {
            it--;
            val -= *it;
            ms.erase(it);
        } else {
            ++ans;
            val = w;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}