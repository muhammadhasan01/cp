#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x > 0; x -= x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x <= n; x += x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void solve() {
    int d, n, k;
    cin >> d >> n >> k;
    BIT<long long> bsum(n + 2);
    BIT<int> bcnt(n + 2);
    vector<vector<int>> in(d + 2), out(d + 2);
    vector<int> att(n + 1);
    vector<pair<int, int>> prs(n); 
    for (int i = 1; i <= n; i++) {
        int h, s, e;
        cin >> h >> s >> e;
        att[i] = h;
        in[s].emplace_back(i);
        out[e + 1].emplace_back(i);
        prs[i - 1] = make_pair(att[i], i);
    }
    sort(prs.begin(), prs.end());
    vector<int> val(n + 1);
    for (int i = 0; i < n; i++) {
        auto [att, id] = prs[i];
        val[id] = i + 1;
    }
    long long ans = 0;
    int cur_cnt = 0;
    for (int day = 1; day <= d + 1; day++) {
        for (int id : in[day]) {
            bcnt.add(val[id], 1);
            bsum.add(val[id], att[id]);
            cur_cnt++;
        }
        for (int id : out[day]) {
            bcnt.add(val[id], -1);
            bsum.add(val[id], -att[id]);
            cur_cnt--;
        }
        if (cur_cnt == 0) {
            continue;
        }
        auto get_pos = [&]() -> int {
            int l = 1, r = n, pos = 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (bcnt.get(mid) <= k) {
                    r = mid - 1;
                    pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            return pos;
        };
        int pos = get_pos();
        long long res = bsum.get(pos);
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}