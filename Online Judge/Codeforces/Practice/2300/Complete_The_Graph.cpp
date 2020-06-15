#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const long long INF = 2e9;

int n, m, s, t;
long long L;
int nu[N], nv[N], w[N];
pair<int, int> par[N];
vector<pair<int, int>> g[N];
vector<int> zero;
int len;

void dismiss() {
    cout << "NO" << '\n';
    exit(0);
}

long long djisktra(int s, int t, long long val) {
    vector<long long> dist(n, INF);
    set<pair<int, long long>> q;
    dist[s] = 0LL;
    q.emplace(s, dist[s]);
    while (!q.empty()) {
        int u = q.begin()->first;
        q.erase(q.begin());
        for (auto& e : g[u]) {
            int v = e.first;
            int idx = e.second;
            long long wgt = w[idx];
            if (wgt == 0LL) wgt = val;
            if (dist[v] > dist[u] + wgt) {
                q.erase(make_pair(v, dist[v]));
                par[v] = make_pair(u, idx);
                dist[v] = dist[u] + wgt;
                q.emplace(v, dist[v]);
            }
        }
    }
    return dist[t];
}

bool can(int id) {
    for (int i = 0; i < len; i++) {
        w[zero[i]] = (i <= id ? 1 : 0);
    }
    return (djisktra(s, t, INF) <= L);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> L >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v >> w[i];
        nu[i] = u, nv[i] = v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    long long cur_inf = djisktra(s, t, INF);
    if (cur_inf < L) dismiss();
    if (cur_inf == L) {
        cout << "YES" << '\n';
        for (int i = 1; i <= m; i++) {
            cout << nu[i] << " " << nv[i] << " " << (w[i] == 0 ? INF : w[i]) << '\n';
        }
        return 0;
    }
    long long cur_1 = djisktra(s, t, 1LL);
    if (cur_1 > L) dismiss();
    if (cur_1 == L) {
        cout << "YES" << '\n';
        for (int i = 1; i <= m; i++) {
            cout << nu[i] << " " << nv[i] << " " << (w[i] == 0 ? 1 : w[i]) << '\n';
        }
        return 0;
    }
    for (int i = 1; i <= m; i++)
        if (w[i] == 0)
            zero.emplace_back(i);
    len = zero.size();
    assert(len > 0);
    int l = 0, r = len - 1;
    int at = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            at = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    at = zero[at];
    l = 1, r = L;
    int res = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        w[at] = mid;
        if (djisktra(s, t, INF) <= L) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    w[at] = res;
    cout << "YES" << '\n';
    for (int i = 1; i <= m; i++) {
        cout << nu[i] << " " << nv[i] << " " << (w[i] == 0 ? INF : w[i]) << '\n';
    }

    return 0;
}