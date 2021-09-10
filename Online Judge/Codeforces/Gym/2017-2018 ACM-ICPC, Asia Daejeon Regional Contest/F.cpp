#include <bits/stdc++.h>

using namespace std;

pair<int, int> get(int n, int move) {
    if (n == 1) {
        return make_pair(1, 1);
    }
    int reg = n * n / 4;
    if (move <= reg) { // region 1
        auto [x, y] = get(n / 2, move);
        return make_pair(y, x);
    } else if (move <= 2 * reg) { // region 2
        move -= reg;
        auto [x, y] = get(n / 2, move);
        return make_pair(x, y + n / 2);
    } else if (move <= 3 * reg) { // region 3
        move -= 2 * reg;
        auto [x, y] = get(n / 2, move);
        return make_pair(x + n / 2, y + n / 2);
    } else { // region 4
        move -= 3 * reg;
        auto [x, y] = get(n / 2, move);
        return make_pair(n - y + 1, n / 2 - x + 1);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    auto [x, y] = get(n, m);
    cout << x << ' ' << y << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}