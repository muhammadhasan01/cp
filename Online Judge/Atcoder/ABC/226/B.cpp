#include <bits/stdc++.h>

using namespace std;

struct VectorHasher {
    const int MOD = 1e9 + 7;
    const int K = 2;
    const vector<int> p = {29, 31};

    vector<vector<int>> pre;

    VectorHasher() : pre(K, vector<int>(1, 1)) {
    }

    template<typename T>
    int compute(int i, int j, T x) {
        while ((int) pre[j].size() <= i) {
            int val = (1LL * pre[j].back() * p[j]) % MOD;
            pre[j].emplace_back(val);
        }
        int ret = (1LL * x * pre[j][i]) % MOD;
        return ret;
    }

    template<typename T>
    vector<int> hash(const vector<T>& a) {
        vector<int> ret(K);
        int n = (int) a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < K; j++) {
                ret[j] = (ret[j] + compute(i, j, a[i])) % MOD;
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    set<vector<int>> st;
    VectorHasher vh;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> v(m);
        for (int j = 0; j < m; j++) {
            cin >> v[j];
        }
        vector<int> h = vh.hash(v);
        st.emplace(v);
    }
    cout << (int) st.size() << '\n';
    
    return 0;
}