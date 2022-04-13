#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int N = 2e5 + 5;

    vector<int> bit(N);
    
    auto add = [&](int x, int val) -> void {
        for ( ; x < N; x += x & -x) {
            bit[x] += val;
        }
    };

    auto get = [&](int x) -> long long {
        long long ret = 0;
        for ( ; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    };
    
    int n, m;
    cin >> n >> m;
    vector<int> pos(n + 5);
    vector<int> a(2 * n + 5);
    for (int i = 1; i <= n; i++) {
        int cur = n + i;
        cin >> a[cur];
        pos[a[cur]] = cur;
        add(cur, 1);
    }
    int cur_pos = n;
    long long res = 0;
    while (m--) {
        int x;
        cin >> x;
        res += get(pos[x] - 1);
        add(pos[x], -1);
        pos[x] = cur_pos--;
        add(pos[x], 1);
    }
    cout << res * 2LL << '\n';

    return 0;
}