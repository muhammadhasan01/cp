#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y;
    node() : x(0), y(0) { }
    node(int _x, int _y) : x(_x), y(_y) { }

    node operator-(const node& b) const {
        return node(x - b.x, y - b.y);
    }

    bool operator==(const node& b) const {
        return (x == b.x && y == b.y);
    }

    int fcd() {
        return __gcd(abs(x), abs(y));
    }

    node unit() {
        int g = __gcd(abs(x), abs(y));
        if (x < 0) {
            return node(-x / g, -y / g);
        } else if (x == 0 && y > 0) {
            return node(0, -y / g);
        } else {
            return node(x / g, y / g);
        }
    }
};

const int N = 1e3 + 5;

int n;
int m, ans;
long long l, r;
node p[N];
vector<int> f[N];
map<pair<int, int>, int> q;

void add(node u) {
    node cc = u.unit();
    auto cur = make_pair(cc.x, cc.y);
    if (q.count(cur) == 0) {
        q[cur] = ++m;
        f[m].clear();
    }
    f[q[cur]].emplace_back(u.fcd());
}

void update(int i, int j, pair<int, int> u) {
    auto [x, y] = u;
    long long s = 1LL * x * x + 1LL * y * y;
    long long sl = (l + s - 1) / s;
    long long sr = r / s;
    sort(f[i].begin(), f[i].end());
    sort(f[j].begin(), f[j].end());
    int k1 = (int) f[j].size() - 1;
    int k2 = k1;
    for (int e : f[i]) {
        while (k1 >= 0 && 1LL * e * f[j][k1] > sr) {
            k1--;
        }
        while (k2 >= 0 && 1LL * e * f[j][k2] >= sl) {
            k2--;
        }
        ans += k1 - k2;
    }
}

void solve() {
    cin >> n;
    cin >> l >> r;
    l = 2 * l; r = 2 * r;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
        q.clear();
        m = 0;
        for (int j = 0; j < n; j++) {
            if (p[i] == p[j]) {
                continue;
            }
            add(p[j] - p[i]);
        }
        for (auto& [key, value] : q) {
            pair<int, int> u = make_pair(-key.second, key.first);
            if (q.count(u) > 0) {
                update(value, q[u], key);
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("points.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}