#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int q;
int n, m;
vector<int> g[N];
int tin[N], low[N], timer = 0;
int comp[N], cmp = 0;
bool onstack[N];
stack<int> st;

void tarjan(int u) {
    tin[u] = low[u] = ++timer;
    st.push(u); onstack[u] = 1;
    for (auto e : g[u]) {
        if (tin[e] == 0) {
            tarjan(e);
            low[u] = min(low[u], low[e]);
        } else if (onstack[e]) {
            low[u] = min(low[u], tin[e]);
        }
    }
    if (low[u] == tin[u]) {
        int w = -1;
        ++cmp;
        do {
            w = st.top(); st.pop();
            comp[w] = cmp;
            onstack[w] = false;
        } while (w != u && !st.empty());
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n >> m;
        while (!st.empty()) st.pop();
        timer = cmp = 0;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            tin[i] = low[i] = onstack[i] = comp[i] = 0;
         }

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            u++, v++;
            g[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) {
            if (tin[i] == 0) tarjan(i);
        }

        cout << cmp << '\n';
    }

    return 0;
}
