#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
long long a[N];
long long ans;
vector<int> adj[N];
vector<int> radj[N];
int deg[N], rdeg[N];

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear(); radj[i].clear();
        deg[i] = rdeg[i] = 0;
    }
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == -1) continue;
        adj[i].emplace_back(x); deg[x]++;
        radj[x].emplace_back(i); rdeg[i]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0)
            q.emplace(i);
    }
    long long ans = 0;
    vector<int> answer;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (a[u] >= 0) {
            ans += a[u];
            answer.emplace_back(u);
        }
        for (auto v : adj[u]) {
            if (a[u] >= 0) a[v] += a[u];
            if (--deg[v] == 0)
                q.emplace(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (rdeg[i] == 0)
            q.emplace(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (a[u] < 0) {
            ans += a[u];
            answer.emplace_back(u);
        }
        for (auto v : radj[u]) {
            if (--rdeg[v] == 0)
                q.emplace(v);
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        cout << answer[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc = 1;
    while (tc--) {
        solve();
    }

    return 0;
}