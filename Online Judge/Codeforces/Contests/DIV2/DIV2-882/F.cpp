#include <bits/stdc++.h>

using namespace std;

const int K = 32;

template<typename T>
struct SparseTable {
    int n;
    vector<vector<T>> dp;
    vector<int> prec;

    SparseTable(vector<T>& a) {
        n = a.size();
        int len = 1;
        int k = 0;
        while (len <= 2 * n) {
            len <<= 1;
            ++k;
        }
        dp.assign(len, vector<T>(k, 0));
        prec.assign(len, 0);
        for (int i = 2; i < 2 * n; i++) {
            prec[i] = prec[i >> 1] + 1;
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = a[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i < n; i++) {
                dp[i][j] = combine(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T combine(const T& a, const T& b) {
        return (a | b);
    }

    T query(int l, int r) {
        int k = prec[r - l + 1];
        return combine(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    int m = n + n;
    vector<int> a(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    SparseTable<int> sp(a);
    vector<pair<long long, int>> posVal;
    for (int i = 0; i < n; i++) {
        posVal.emplace_back(i, a[i]);
    }
    for (int i = n + 1, j = 1; i < m; i++, j++) {
        int lastVal = a[i];
        int lastPos = i;
        for (int rep = 0; rep < K; rep++) {
            int l = 0, r = lastPos - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sp.query(mid, i) != lastVal) {
                    at = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (at == -1) {
                break;
            }
            int len = i - at + 1;
            long long curIdx = 1LL * (len - 1) * (n - 1) + j;
            int curVal = sp.query(at, i);
            posVal.emplace_back(curIdx, curVal);
            lastVal = curVal;
            lastPos = at;
        }
    }
    sort(posVal.begin(), posVal.end());
    int sz = (int) posVal.size();
    for (int i = 1; i < sz; i++) {
        posVal[i].second = max(posVal[i].second, posVal[i - 1].second);
    }
    while (q--) {
        int v;
        cin >> v;
        int l = 0, r = sz - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (posVal[mid].second > v) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at == -1) {
            cout << -1 << '\n';
            continue;
        }
        cout << posVal[at].first + 1 << '\n';
    }
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