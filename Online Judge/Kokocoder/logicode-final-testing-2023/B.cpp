#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par;
    
    DSU(int _n) : n(_n), par(_n) {
        iota(par.begin(), par.end(), 0);
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) {
            return false;
        }
        if (pu < pv) {
            swap(pu, pv);
        }
        par[pv] = pu;
        return true;
    }
};


template<typename T>
struct DequeMin {
    deque<T> dq;

    bool isEmpty() {
        return dq.empty();
    }

    void add(T x) {
        while (!dq.empty() && dq.back() > x) {
            dq.pop_back();
        }
        dq.emplace_back(x);
    }

    void remove(T x) {
        if (dq.empty() || dq.front() != x) {
            return;
        }
        dq.pop_front();
    }

    T getMin() {
        return dq.front();
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    DSU dsu(n + 1);

    auto mergeLand = [&](int l, int r) -> void {
        int cur = l;
        while (cur + 1 <= r) {
            dsu.merge(cur, cur + 1);
            cur = dsu.fpar(cur);
        }
    };

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        mergeLand(l, r);
    }
    vector<long long> sums(n + 1);
    vector<int> cnts(n + 1);
    vector<int> comp;
    comp.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        int j = dsu.fpar(i);
        sums[j] += a[i];
        cnts[j]++;
        if (i == j) {
            comp.emplace_back(j);
        }
    }
    int len = (int) comp.size() - 1;
    vector<int> prefCnt(len + 1);
    vector<long long> prefSum(len + 1);
    for (int i = 1; i <= len; i++) {
        int j = comp[i];
        prefCnt[i] = prefCnt[i - 1] + cnts[j];
        prefSum[i] = prefSum[i - 1] + sums[j];
    }
    long long ans = 0;
    DequeMin<long long> dqm;
    for (int l = 1, r = 1; r <= len; r++) {
        dqm.add(prefSum[r - 1]);
        while (prefCnt[r] - prefCnt[l - 1] > k) {
            dqm.remove(prefSum[l - 1]);
            l++;
        }
        if (l > r) {
            continue;
        }
        long long curMin = dqm.getMin();
        long long res = prefSum[r] - curMin;
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}