#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int m = n * k;
    int r = (n + (k - 1) - 1) / (k - 1);
    vector<int> c(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    vector<vector<int>> x(n + 1);
    for (int i = 1; i <= m; i++) {
        x[c[i]].emplace_back(i);
    }
    vector<pair<int, int>> intervals(n + 1);
    vector<int> col(n);
    iota(col.begin(), col.end(), 1);
    for (int i = 1; !col.empty(); i++) {
        sort(col.begin(), col.end(), [&](int& lhs, int& rhs) {
            return x[lhs][i] < x[rhs][i];
        });
        int len = min(r, (int) col.size());
        for (int j = 0; j < len; j++) {
            intervals[col[j]] = make_pair(x[col[j]][i - 1], x[col[j]][i]);
        }
        col.erase(col.begin(), col.begin() + len);
    }
    for (int i = 1; i <= n; i++) {
        auto [l, r] = intervals[i];
        cout << l << ' ' << r << '\n';
    }
    
    return 0;
}