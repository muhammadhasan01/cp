#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6;

int fen[N + 1];

void add(int x, int v) {
    for (int i = x + 1; i <= N + 1; i += i & -i)
        fen[i - 1] += v;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i; i &= i - 1)
        res += fen[i - 1];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long ans = 1;
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> a, b;
    for (int i = 0; i < n; ++i) {
        int y, l, r;
        cin >> y >> l >> r;
        if (l == 0 && r == N)
            ++ans;
        a.emplace_back(l, y, 1);
        a.emplace_back(r + 1, y, -1);
    }
    for (int i = 0; i < m; ++i) {
        int x, l, r;
        cin >> x >> l >> r;
        if (l == 0 && r == N)
            ++ans;
        b.emplace_back(x, l, r);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    for (auto [x, l, r] : b) {
        while (i < 2 * n && get<0>(a[i]) <= x) {
            auto [tt, y, v] = a[i++];
            add(y, v);
        }
        ans += sum(r + 1) - sum(l);
    }
    cout << ans << "\n";
    return 0;
}
