#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int tc, n;
vector<int> g[N];
bool onstack[N];
int tin[N], low[N], comp[N], timer = 0;
int cmp = 0;
stack<int> st;

void tarjan(int u) {
    st.push(u); onstack[u] = 1;
    tin[u] = low[u] = ++timer;
    for (auto v : g[u]) {
        if (tin[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (onstack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (low[u] == tin[u]) {
        int w = 0; ++cmp;
        do {
            w = st.top(); st.pop();
            comp[w] = cmp;
            onstack[w] = 0;
        } while (w != u && !st.empty());
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        timer = 0;
        cmp = 0;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            tin[i] = low[i] = onstack[i] = comp[i] = 0;
        }
        while (!st.empty()) st.pop();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char x;
                cin >> x;
                if (x == 'Y') g[i].push_back(j);
            }
        }
        for (int i = 1; i <= n; i++) if (tin[i] == 0) tarjan(i);
        cout << cmp << '\n';
    }

    return 0;
}
