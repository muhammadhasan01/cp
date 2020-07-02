#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;

int tc;
int n;
int a[N];
pair<int, int> b[N];

inline void move(int pos) {
    int temp = a[pos + 2];
    for (int i = pos + 2; i >= pos + 1; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = temp;
}

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }
    sort(b + 1, b + 1 + n);
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && b[i].first == b[i - 1].first) idx = i; 
        a[b[i].second] = i;
    }
    int cur = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) cur ^= 1;
        }
    }
    if (cur) {
        if (idx == -1) {
            cout << -1 << '\n';
            return;
        }
        swap(a[b[idx].second], a[b[idx - 1].second]);
    }
    vector<int> ans;
    set<int> s[N];
    for (int i = 1; i <= n; i++) {
        s[a[i]].emplace(i);
    }
    int mostLeft = 1;
    for (int x = 1; x <= n; x++) {
        if (s[x].empty()) continue;
        if (mostLeft == n - 2) break;
        while (!s[x].empty()) {
            int cur = *s[x].begin();
            if (cur == mostLeft) {
                mostLeft++;
                if (mostLeft == n - 2) break;
                s[x].erase(cur);
            } else {
                int pos = (cur == mostLeft + 1 ? cur - 1 : cur - 2);
                ans.emplace_back(pos);
                for (int i = pos; i <= pos + 2; i++) {
                    s[a[i]].erase(i);
                }
                move(pos);
                for (int i = pos; i <= pos + 2; i++) {
                    s[a[i]].emplace(i);
                }
            }
        }
    }
    for (int it = 0; it < 5; it++) {
        bool flag = true;
        for (int i = n - 1; i <= n; i++) {
            if (a[i - 1] > a[i]) {
                flag = false;
                break;
            }
        }
        if (flag) break;
        int pos = n - 2;
        ans.emplace_back(pos);
        move(pos);
    }
    for (int i = 2; i <= n; i++) assert(a[i - 1] <= a[i]);
    assert(n * n >= (int) ans.size());
    cout << ans.size() << '\n';
    for (auto& e : ans) cout << e << " ";
    cout << '\n';
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