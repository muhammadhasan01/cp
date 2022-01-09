#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int K = 26;

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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    // check if we can
    {
        string p = s;
        sort(p.begin(), p.end());
        if (p >= t) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<deque<int>> pos(K);
    for (int i = 0; i < n; i++) {
        int num = s[i] - 'a';
        pos[num].emplace_back(i);
    }
    long long ans = INF;
    // base case: find < t[0]
    {
        int num = t[0] - 'a';
        long long cst = INF;
        for (int x = num - 1; x >= 0; x--) {
            if (pos[x].empty()) {
                continue;
            }
            cst = min(cst, 1LL * pos[x].front());
        }
        ans = min(ans, cst);
    }
    // other case: make [0...i] the same (0 <= i < n - 1) and i + 1 less
    long long cst = 0;
    BIT<int> bit(n + 5);
    for (int i = 0; i < n - 1; i++) {
        int num = t[i] - 'a';
        if (pos[num].empty()) {
            break;
        }
        int j = pos[num].front();
        pos[num].pop_front();
        bit.add(j, 1);
        cst += max(0, j + bit.get(j + 1) - i);
        // we must find < t[i + 1]
        {
            int cur = t[i + 1] - 'a';
            long long lft = INF;
            for (int x = cur - 1; x >= 0; x--) {
                if (pos[x].empty()) {
                    continue;
                }
                int cur = pos[x].front();
                long long val = cur + bit.get(cur + 1);
                lft = min(lft, val);
            }
            if (lft != INF) {
                long long res = cst + max(0LL, (lft - (i + 1)));
                ans = min(ans, res);
            }
        }
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
        solve();
    }
    
    return 0;
}