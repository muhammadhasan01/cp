#include <bits/stdc++.h>

using namespace std;

int tc;
int n, m, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> a >> b;
        vector<vector<int>> g(n + 1);
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<bool> fa(n + 1), fb(n + 1);
        queue<int> qa, qb;
        qa.push(a);
        while (!qa.empty()) {
            int cur = qa.front();
            qa.pop();
            if (fa[cur] == 1 || cur == b) continue;
            fa[cur] = 1;
            for (auto e : g[cur]) {
                if (e == b || fa[e] == 1) continue;
                qa.push(e);
            }
        }
        qb.push(b);
        while (!qb.empty()) {
            int cur = qb.front();
            qb.pop();
            if (fb[cur] == 1 || cur == a) continue;
            fb[cur] = 1;
            for (auto e : g[cur]) {
                if (e == a || fb[e] == 1) continue;
                qb.push(e);
            }
        }
        long long resa = 0, resb = 0;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == 1 && fb[i] == 0 && i != a) resa++;
            if (fa[i] == 0 && fb[i] == 1 && i != b) resb++;
        }
        cout << resa * resb << '\n';
    }

    return 0;
}
