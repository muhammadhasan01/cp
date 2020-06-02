#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct person {
    int b, f;
    long long d;
    bool operator<(const person& other) {
        if (b == other.b)
            return f < other.f;
        return b < other.b;
    }
};

int n;
person p[N];
long long t[4 * N];

void update(int v, int s, int e, int pos, long long val) {
    if (s == e && s == pos) {
        t[v] = max(t[v], val);
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) {
        update(v << 1, s, mid, pos, val);
    } else {
        update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

long long get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0LL;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    return max(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    set<int> s1, s2;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].b >> p[i].f >> p[i].d;
        s1.emplace(p[i].b);
        s2.emplace(p[i].f);
    }
    map<int, int> mp1, mp2;
    int ord_1 = 0, ord_2 = 0;
    for (auto& e : s1) mp1[e] = ++ord_1;
    for (auto& e : s2) mp2[e] = ++ord_2;
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        p[i].b = mp1[p[i].b];
        p[i].f = mp2[p[i].f];
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].b == p[i + 1].b && p[i].f == p[i + 1].f) {
            p[i + 1].d += p[i].d;
        }
    }
    queue<pair<int, long long>> q;
    for (int i = 1; i <= n; i++) {
        if (p[i].b != p[i - 1].b) {
            while (!q.empty()) {
                auto temp = q.front();
                q.pop();
                update(1, 1, n, temp.first, temp.second);
            }
        }
        long long cur = p[i].d + get(1, 1, n, 1, p[i].f - 1);
        q.emplace(p[i].f, cur);
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}