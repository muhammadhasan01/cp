#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 2e5 + 5;

int n, m, k;
int c[N];
int like[N];
long long res[4];
long long sum;
vector<int> liked[4];
set<pair<int, int>> in, out;

void add(int id) {
    out.emplace(c[id], id);
}

void rem(int id) {
    pair<int, int> p = make_pair(c[id], id);
    if (in.count(p)) {
        in.erase(p);
        sum -= c[id];
    } else {
        out.erase(p);
    }
}

void fix() {
    while (!in.empty() && !out.empty() && *out.begin() < *prev(in.end())) {
        auto cur = *out.begin();
        out.erase(out.begin());
        in.insert(cur);
        sum += cur.first;
    }
}

void fix_len(int len) {
    fix();
    while ((int) in.size() > len) {
        auto cur = *prev(in.end());
        in.erase(prev(in.end()));
        out.insert(cur);
        sum -= cur.first;
    }
    while ((int) in.size() < len && !out.empty()) {
        auto cur = *out.begin();
        out.erase(out.begin());
        in.insert(cur);
        sum += cur.first;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int it = 0; it < 2; it++) {
        int len;
        cin >> len;
        while (len--) {
            int x;
            cin >> x;
            like[x] |= (1 << it);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (like[i] == 1 || like[i] == 2) {
            res[like[i]] += c[i];
        } else {
            add(i);
        }
        liked[like[i]].emplace_back(i);
    }
    for (int i = 1; i <= 3; i++) {
        sort(liked[i].begin(), liked[i].end(), [&](int x, int y) {
            return c[x] < c[y];
        });
    }
    long long ans = INF;
    long long sum_both = 0;
    for (int both = 0; both <= k; both++) {
        int left = k - both;
        for (int it = 1; it <= 2; it++) {
            while ((int) liked[it].size() > left) {
                int id = liked[it].back();
                liked[it].pop_back();
                add(id);
                res[it] -= c[id];
            }
        }
        int outside = m - both - left - left;
        if ((int) liked[1].size() == left && (int) liked[2].size() == left && outside >= 0) {
            fix_len(outside);
            if ((int) in.size() == outside) {
                ans = min(ans, sum_both + res[1] + res[2] + sum);
            }
        }
        if (both >= (int) liked[3].size()) break;
        int id = liked[3][both];
        sum_both += c[id];
        rem(id);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}