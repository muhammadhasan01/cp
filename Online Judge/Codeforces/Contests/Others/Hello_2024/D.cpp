#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<set<int>> st(n, {-1, n});
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st[a[i]].emplace(i);
    }
    int zero = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (zero != -1) {
                cout << "NO" << '\n';
                return;
            }
            zero = i;
        }
    }
    if (zero == -1) {
        cout << "NO" << '\n';
        return;
    }
    int cnt = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(0, n - 1, zero);
    while (!q.empty()) {
        auto [l, r, i] = q.front();
        q.pop();
        if (l > r) {
            continue;
        }
        if (l == r) {
            ++cnt;
            continue;
        }
        int val = a[i] + 1;
        int nl = l - 1, lpos = -1;
        // left
        {
            auto it = st[val].lower_bound(l);
            if (*it < i) {
                lpos = *it;
                nl = i - 1;
                if (next(it) != st[val].end()) {
                    nl = min(nl, *next(it) - 1);
                }
            }
        }
        int nr = r + 1, rpos = -1;
        // right
        {
            auto it = prev(st[val].upper_bound(r));
            if (*it > i) {
                rpos = *it;
                nr = i + 1;
                if (it != st[val].begin()) {
                    nr = max(nr, *prev(it) + 1);
                }
            }
        }
        if (lpos != -1) {
            q.emplace(l, nl, lpos);
        }
        if (rpos != -1) {
            q.emplace(nr, r, rpos);
        }
        if (lpos != -1 || rpos != -1) {
            q.emplace(nl + 1, nr - 1, i);
        }
    }
    cout << (cnt == n ? "YES" : "NO") << '\n';
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