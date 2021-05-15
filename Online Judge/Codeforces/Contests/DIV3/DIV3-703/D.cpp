#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int a[N];
int d[N];
vector<int> adj[N];

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
}

int build(int l, int r) {
    int maxi = 0;
    int pos = -1;
    for (int i = l; i <= r; i++) {
        if (a[i] > maxi) {
            maxi = a[i];
            pos = i;
        }
    }
    int x = (l <= pos - 1 ? build(l, pos - 1) : -1);
    int y = (pos + 1 <= r ? build(pos + 1, r) : -1);
    if (x != -1) adj[pos].emplace_back(x);
    if (y != -1) adj[pos].emplace_back(y);
    return pos;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init();
    int s = build(1, n);
    queue<int> q;
    d[s] = 0;
    q.emplace(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            d[v] = 1 + d[u];
            q.emplace(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " \n"[i == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}