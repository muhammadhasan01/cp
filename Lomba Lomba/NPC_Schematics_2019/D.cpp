#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int par[N], sz[N];
pair<int,int> absi[N], ordi[N];

int findp(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = findp(par[x]);
}

void merge(int a, int b) {
    int pa = findp(a);
    int pb = findp(b);
    if (pa != pb) {
        if (sz[pa] < sz[pb]) swap(pa, pb);
        sz[pa] += sz[pb];
        par[pb] = pa;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    int l1 = 0, l2 = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        absi[++l1] = {x, i};
        ordi[++l2] = {y, i};
    }
    sort(absi + 1, absi + 1 + l1);
    sort(ordi + 1, ordi + 1 + l2);

    priority_queue<pair<long long, pair<int,int>>> pq;
    pair<int,int> t1, t2;
    for (int i = 1; i <= l1 - 1; i++) {
        t1 = absi[i];
        t2 = absi[i + 1];
        pq.push({-abs(t1.first - t2.first), {t1.second, t2.second}});
    }
    for (int i = 1; i <= l2 - 1; i++) {
        t1 = ordi[i];
        t2 = ordi[i + 1];
        pq.push({-abs(t1.first - t2.first), {t1.second, t2.second}});
    }
    long long res = 0;
    int u, v;
    while (!pq.empty()) {
        pair<long long, pair<int,int> > cur = pq.top();
        pq.pop();
        u = cur.second.first;
        v = cur.second.second;
        if (findp(u) != findp(v)) {
            merge(u, v);
            res -= cur.first;
        }
    }
    cout << res << '\n';

    return 0;
}
