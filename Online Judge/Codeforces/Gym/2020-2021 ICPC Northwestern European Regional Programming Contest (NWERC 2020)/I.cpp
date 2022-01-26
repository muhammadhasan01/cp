#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 405;
const int K = 3;

pii times[K][N][N];
bool not_ok[K][K][N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<vector<int>> t(K, vector<int>(n));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    for (int it = 0; it < K; it++) {
        for (int s = 0; s < n; s++) {
            for (int i = s, j = 0, curtime = 0; j < n; j++, i++) {
                if (i >= n) {
                    i = 0;
                }
                times[it][s][i] = make_pair(curtime, curtime + t[it][i]);
                curtime += t[it][i];
                curtime += d[i];
            }
        }
    }
    auto intersect = [&](pii lhs, pii rhs) -> bool {
        if (lhs.first > rhs.first) {
            swap(lhs, rhs);
        }
        auto [lx, rx] = lhs;
        auto [ly, ry] = rhs;
        return rx > ly;
    };
    vector<pii> turns = {{0, 1}, {1, 2}, {0, 2}};
    for (auto [x, y] : turns) {
        for (int sx = 0; sx < n; sx++) {
            for (int sy = 0; sy < n; sy++) {
                for (int i = 0; i < n; i++) {
                    if (intersect(times[x][sx][i], times[y][sy][i])) {
                        not_ok[x][y][sx][sy] = true;
                        break;
                    }
                }
            }
        }
    }
    for (int sx = 0; sx < n; sx++) {
        for (int sy = 0; sy < n; sy++) {
            if (sx == sy || not_ok[0][1][sx][sy]) {
                continue;
            }
            for (int sz = 0; sz < n; sz++) {
                if (sy == sz || not_ok[1][2][sy][sz]) {
                    continue;
                }
                if (sx == sz || not_ok[0][2][sx][sz]) {
                    continue;
                }
                cout << sx + 1 << ' ' << sy + 1 << ' ' << sz + 1 << '\n';
                return 0;
            }
        }
    }
    cout << "impossible" << '\n';
    
    return 0;
}