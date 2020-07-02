#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int c[4][N];
short int b[N], bb[N];
vector<int> g[N];
vector<int> p = {1, 2, 3};
long long k;

void dfs(int u, int pr, int t) {
    k += c[p[t]][u];
    bb[u] = p[t];
    for (auto e : g[u]) {
        if (e != pr) {
            dfs(e, u, (t + 1) % 3);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if ((int) g[i].size() == 3) {
            puts("-1");
            return 0;
        }
    }

    int root;
    for (int i = 1; i <= n; i++) {
        if ((int) g[i].size() == 1) {
            root = i;
            break;
        }
    }

    long long ans = 1e18;
    do {
        k = 0;
        dfs(root, root, 0);
        if (ans > k) {
            ans = k;
            for (int i = 1; i <= n; i++) {
                b[i] = bb[i];
            }
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
