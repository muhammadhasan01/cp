#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, m;
vector<int> dig[N], lcs[N], sym[N];

int move(int i, int j, int k) {
    if ((int) dig[i].size() == 0) return 1e9;
    if ((int) lcs[j].size() == 0) return 1e9;
    if ((int) sym[k].size() == 0) return 1e9;
    int digs = min(dig[i][0] - 1, m + 1 - dig[i].back());
    int lcss = min(lcs[j][0] - 1, m + 1 - lcs[j].back());
    int syms = min(sym[k][0] - 1, m + 1 - sym[k].back());
    return digs + lcss + syms;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if ('0' <= x && x <= '9') {
                dig[i].push_back(j);
            } else if ('a' <= x && x <= 'z') {
                lcs[i].push_back(j);
            } else if (x == '#' || x == '*' || x == '&') {
                sym[i].push_back(j);
            }
        }
    }
    vector<bool> v(n, true);
    vector<int> pos(3);
    for (int i = 0; i < 3; i++) v[i] = false;
    int ans = 1e9;
    do {
        for (int i = 0, j = 0; i < n; i++) {
            if (!v[i]) pos[j++] = i + 1;
        }
        do {
            ans = min(ans, move(pos[0], pos[1], pos[2]));
        } while (next_permutation(pos.begin(), pos.end()));
        if (ans == 0) {
            cout << 0 << '\n';
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << '\n';

    return 0;
}
