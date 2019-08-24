#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
vector<int> g[N];
bitset<N> vis;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (a[1] != 1) {
        cout << "No" << '\n';
        return 0;
    }

    int pos = 1;
    queue<int> q;
    q.push(a[pos]);
    vis[a[pos]] = 1;
    bool ok = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        set<int> s;
        for (auto e : g[u]) {
            if (!vis[e]) s.insert(e);
        }

        int temp = pos;
        int len = pos + s.size();

        if (len > n) {
            ok = false;
            break;
        }
        for (int i = pos + 1; i <= len; i++) {
            if (s.find(a[i]) == s.end()) {
                ok = false;
            } else {
                q.push(a[i]);
                vis[a[i]] = 1;
                s.erase(a[i]);
            }
            if (!ok) break;
        }
        if (!ok) break;
        pos = len;
    }
    puts(ok ? "Yes" : "No");

    return 0;
}
