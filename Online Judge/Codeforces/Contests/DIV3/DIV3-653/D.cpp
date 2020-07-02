#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
long long k;

void solve() {
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= k;
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> w;
    int len = v.size();
    int cur = 1;
    int now = v[0];
    for (int i = 1; i < len; i++) {
        if (v[i] == now) {
            ++cur;
        } else {
            w.emplace_back(now, cur);
            now = v[i];
            cur = 1;
        }
    }
    w.emplace_back(now, cur);
    long long res = 0;
    for (auto& e : w) {
        if (e.first == 0) continue;
        long long need = (1LL) * (e.second - 1) * k + (1LL) * (k - e.first) + 1LL;
        res = max(res, need);
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}