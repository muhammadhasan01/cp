#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, c;
    cin >> n >> c;
    vector<int> lens(n);
    vector<vector<int>> v(n);
    vector<vector<int>> same(n);
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        cin >> lens[i];
        v[i].resize(lens[i]);
        same[i].resize(lens[i] + 1);
        for (int j = 0; j < lens[i]; j++) {
            cin >> v[i][j];
            v[i][j]--;
        }
        max_len = max(max_len, lens[i]);
    }
    auto dismiss = [&]() -> void {
        cout << -1 << '\n';
        exit(0);
    };
    vector<tuple<int, int, int>> ranges; // (l, r, j)
    ranges.emplace_back(0, n - 1, 0);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= min(lens[i - 1], lens[i]); j++) {
            int x = v[i - 1][j - 1];
            int y = v[i][j - 1];
            if (x == y) {
                same[i][j] = same[i - 1][j] + 1;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= lens[i]; j++) {
            if (same[i][j] == 0) {
                continue;
            }
            if (i + 1 < n && same[i + 1][j] > 0) {
                continue;
            }
            ranges.emplace_back(i - same[i][j], i, j);
        }
    }
    int need = 0;
    int mini = INF;
    auto get = [&](int i, int j) -> int {
        if (j >= lens[i]) {
            return -1;
        }
        return (v[i][j] + need) % c;
    };
    for (auto& [l, r, j] : ranges) {
        set<int> st;
        int cur = 0;
        for (int i = l; i <= r; i++) {
            int u = get(i, j);
            auto it = st.upper_bound(u);
            if (it == st.end()) {
                if (!st.empty()) {
                    bool ok = true;
                    if ((int) st.size() == 1) {
                        if (*st.begin() == u) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        mini = min(mini, need + c - u);
                    }
                }
            } else {
                if (u == -1) {
                    dismiss();
                }
                cur = max(cur, c - *it);
            }
            st.emplace(u);
        }
        need += cur;
        if (need > mini) {
            dismiss();
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < max(lens[i - 1], lens[i]); j++) {
            int x = get(i - 1, j);
            int y = get(i, j);
            if (x < y) {
                break;
            }
            if (x > y) {
                dismiss();
            }
        }
    }
    cout << need << '\n';
    
    return 0;
}