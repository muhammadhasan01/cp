#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define inchar          getchar
#define outchar(x)      putchar(x)

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = inchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = inchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = inchar());
    for (; c > 47 && c < 58; c = inchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}
template<typename T> void outpos(T n) {
    if (n < 0) {
        outchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) outchar(snum[i--]);
    outchar('\n');
}

typedef pair<long long, int> pli;

const int N = 1e3 + 5;
const long long INF = 1e16;

struct delivery {
    long long s, u, t;
};

int n, m, k;
vector<pair<int, int>> adj[N];
long long dist[N][N];
long long pre[N];
long long dp[N];
delivery d[N];

void dijkstra(int s) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[s][s] = 0;
    pq.emplace(dist[s][s], s);
    while (!pq.empty()) {
        pli cur = pq.top();
        pq.pop();
        long long d = cur.first;
        int u = cur.second;
        if (d != dist[s][u]) continue;
        for (auto& e : adj[u]) {
            int v = e.first;
            long long w = e.second;
            if (dist[s][v] > dist[s][u] + w) {
                dist[s][v] = dist[s][u] + w;
                pq.emplace(dist[s][v], v);
            }
        }
    }
}

bool can(long long x) {
    for (int i = 1; i <= k; i++) {
        dp[i] = INF;
        long long maxi = -INF;
        for (int j = i; j >= 1; j--) {
            if (j < i) maxi = max(maxi, pre[j + 1] - d[j + 1].s - x);
            if (dp[j - 1] == INF) break;
            long long curtime = max(d[i].t, dp[j - 1] + dist[d[j - 1].u][1]);
            curtime += dist[1][d[j].u];
            if (curtime - d[j].s > x) continue;
            long long default_time = pre[j];
            long long dif = (curtime - default_time);
            if (j < i && maxi + dif > 0) continue;
            curtime += pre[i] - pre[j];
            dp[i] = min(curtime, dp[i]);
        }
    }
    return (dp[k] < INF);
}

int main() {
    inpos(n), inpos(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = INF;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        inpos(u), inpos(v), inpos(w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++)
        dijkstra(i);
    inpos(k);
    d[0].u = 1;
    for (int i = 1; i <= k; i++) {
        cin >> d[i].s >> d[i].u >> d[i].t;
    }
    for (int i = 1; i <= k; i++) {
        pre[i] = pre[i - 1] + dist[d[i].u][d[i - 1].u];
    }
    long long l = 0, r = INF, ans = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    outpos(ans);
 
    return 0;
}