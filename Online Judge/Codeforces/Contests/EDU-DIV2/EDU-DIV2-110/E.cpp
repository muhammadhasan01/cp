#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int L = 20;

int q;
int up[N][L];
int a[N], c[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q >> a[0] >> c[0];
    for (int i = 0; i < L; i++) {
        up[0][i] = 0;
    }
    for (int it = 1; it <= q; it++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p;
            cin >> p >> a[it] >> c[it];
            up[it][0] = p;
            for (int i = 1; i < L; i++) {
                up[it][i] = up[up[it][i - 1]][i - 1];
            }
        } else if (tp == 2) {
            int u, w;
            cin >> u >> w;
            int gold = 0;
            long long money = 0;
            while (true) {
                if (w == 0) break;
                if (u != 0 && a[up[u][0]] > 0) {
                    int v = u;
                    for (int i = L - 1; i >= 0; i--) {
                        if (a[up[v][i]] > 0) {
                            v = up[v][i];
                        }
                    }
                    int take = min(w, a[v]);
                    a[v] -= take; w -= take;
                    gold += take;
                    money += 1LL * take * c[v];
                } else {
                    int take = min(w, a[u]);
                    a[u] -= take;
                    gold += take;
                    money += 1LL * take * c[u];
                    break;
                }
            }
            cout << gold << ' ' << money << endl;
        }
    }

    return 0;
}