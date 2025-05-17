#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int L = 20;
const int K = 4;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    vector<int> y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    vector<pii> cand(K, {-INT_MAX, -1});

    auto updMx = [&](pii& lhs, pii rhs) {
        if (rhs.first > lhs.first) {
            lhs = rhs;
        } else if (rhs.first == lhs.first && rhs.second < lhs.second) {
            lhs = rhs;
        }
    };

    auto updCand = [&](int i) -> void {
        int idx = 0;
        for (int dx : {-1, 1}) {
            for (int dy : {-1, 1}) {
                updMx(cand[idx++], {dx * x[i] + dy * y[i], i});
            }
        }
    };

    vector up(n + 1, vector<int>(L));
    up[n][0] = n;
    updCand(n);
    for (int i = n - 1; i >= 1; i--) {
        pair<int, int> chosen = {0, n};
        for (auto [_, j] : cand) {
            int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            updMx(chosen, {dist, j});
        }
        up[i][0] = chosen.second;
        updCand(i);
    }
    for (int l = 1; l < L; l++) {
        for (int u = 1; u <= n; u++) {
            up[u][l] = up[up[u][l - 1]][l - 1];
        }
    }
    while (q--) {
        int p, k;
        cin >> p >> k;
        for (int l = L - 1; l >= 0; l--) {
            if (k & (1 << l)) {
                p = up[p][l];
            }
        }
        cout << p << '\n';
    }
    
    return 0;
}