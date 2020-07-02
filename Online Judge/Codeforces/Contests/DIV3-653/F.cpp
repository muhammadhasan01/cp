#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;

int tc;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    set<int> s[N];
    for (int i = 1; i <= n; i++) {
        s[a[i]].emplace(i);
    }
    int mostRight = n;
    for (int i = N - 1; i >= 1; i--) {
        if (s[i].empty()) continue;
        if (mostRight == 3) break;
        while (!s[i].empty()) {
            int cur = *s[i].rbegin();
            if (cur == mostRight) {
                mostRight--;
                if (mostRight == 3) break;
                s[i].erase(cur);
            } else {
                int pos = (cur == mostRight - 1 ? cur - 1 : cur);
                for (int i = pos; i <= pos + 2; i++) {
                    s[a[i]].erase(i);
                }
                ans.emplace_back(pos);
                int temp = a[pos + 2];
                for (int i = pos + 2; i >= pos + 1; i--) {
                    a[i] = a[i - 1];
                }
                a[pos] = temp;
                for (int i = pos; i <= pos + 2; i++) {
                    s[a[i]].emplace(i);
                }
            }
        }
    }
    for (int it = 0; it < 5; it++) {
        bool flag = true;
        for (int i = 1; i < 3; i++) {
            if (a[i + 1] < a[i]) {
                flag = false;
                break;
            }
        }
        if (flag) break;
        int pos = 1;
        ans.emplace_back(pos);
        int temp = a[pos + 2];
        for (int i = pos + 2; i >= pos + 1; i--) {
            a[i] = a[i - 1];
        }
        a[pos] = temp;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            cout << -1 << '\n';
            return;
        }
    }
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