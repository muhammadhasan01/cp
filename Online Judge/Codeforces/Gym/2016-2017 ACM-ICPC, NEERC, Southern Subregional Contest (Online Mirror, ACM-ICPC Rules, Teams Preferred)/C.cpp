// TLE
#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar('\n');
}

typedef pair<int, int> pii;

const int N = 5e3 + 5;
const int INF = 1e9;

int n, m, w, q;
int g, r;
long long a;
vector<int> adj[N];
vector<pii> bulmart[N];
bitset<N> mart;

bool can(int distance, const vector<int>& marts, const vector<int>& distances) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto& e : marts) {
        if (distances[e] > distance) break;
        for (auto& el : bulmart[e]) pq.emplace(el);
    }
    int need = r;
    long long cost = 0;
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int cur = min(need, temp.second);
        cost += (1LL) * cur * temp.first;
        if (cost > a) return false;
        need -= cur;
        if (need == 0) break;
    }
    return (need == 0);
}

void query() {
    inpos(g), inpos(r), inpos(a);
    queue<int> q;
    vector<int> distances(n + 1, INF);
    vector<int> marts;
    q.emplace(g); distances[g] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (mart[u] == 1) {
            marts.emplace_back(u);
        }
        for (auto v : adj[u]) {
            if (distances[v] <= 1 + distances[u]) continue;
            q.emplace(v);
            distances[v] = 1 + distances[u];
        }
    }
    int l = 0, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid, marts, distances)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    outpos(ans);
}

int main() {
    inpos(n), inpos(m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        inpos(u), inpos(v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    inpos(w);
    for (int i = 1; i <= w; i++) {
        int c, k, p;
        inpos(c), inpos(k), inpos(p);
        mart[c] = 1;
        bulmart[c].emplace_back(p, k);
    }
    inpos(q);
    while (q--) {
        query();
    }
    return 0;
}