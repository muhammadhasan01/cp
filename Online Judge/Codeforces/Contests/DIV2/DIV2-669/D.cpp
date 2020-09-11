#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int NMAX = (1 << 20);
const int L = 20;

int n;
int a[N];
int pre[NMAX];
pair<int, int> sp[NMAX][L];
vector<int> adj[N];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    return make_pair(max(a.first, b.first), min(a.second, b.second));
}

int get(int l, int r, bool mini) {
    int k = pre[r - l + 1];
    pair<int, int> ret = merge(sp[l][k], sp[r - (1 << k) + 1][k]);
    if (mini)
        return ret.second;
    else
        return ret.first;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
        adj[i].emplace_back(i + 1);
    for (int i = 2; i < NMAX; i++) {
        pre[i] = pre[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        sp[i][0] = make_pair(a[i], a[i]);
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            sp[i][j] = merge(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        {
            int L = i + 1;
            int l = L, r = n, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(L, mid, false) >= a[i]) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (at != -1) {
                adj[i].emplace_back(at);
            }
        }
        {
            int L = i + 1;
            int l = L, r = n, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(L, mid, true) <= a[i]) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (at != -1) {
                adj[i].emplace_back(at);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        {
            int R = i - 1;
            int l = 1, r = R, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(mid, R, false) >= a[i]) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at != -1) {
                adj[at].emplace_back(i);
            }
        }
        {
            int R = i - 1;
            int l = 1, r = R, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get(mid, R, true) <= a[i]) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at != -1) {
                adj[at].emplace_back(i);
            }
        }
    }
    vector<int> ans(n + 1, 0);
    queue<int> q;
    q.emplace(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (ans[v]) continue;
            ans[v] = 1 + ans[u];
            q.emplace(v);
        }
    }
    cout << ans[n] << '\n';

    return 0;
}