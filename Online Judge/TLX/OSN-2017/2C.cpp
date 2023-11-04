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
    
    string useless;
    cin >> useless;
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto getSequence = [&](int i, int j, long long x, long long y) -> vector<long long> {
        vector<long long> ret(4);
        // ret[0] / ret[1] + ret[2] / ret[3] * (i - 1) 
        long long len = j - i;
        long long dif = y - x;
        {
            long long g = __gcd(abs(len), abs(dif));
            ret[2] = dif / g;
            ret[3] = len / g;
        }
        {
            long long P = ret[3] * x - ret[2] * i;
            long long Q = ret[3];
            long long g = __gcd(abs(P), abs(Q));
            ret[0] = P / g;
            ret[1] = Q / g;
        }
        return ret;
    };

    VectorHasher vh;
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<long long> S1 = getSequence(i, j, a[i], a[j]);
            vector<long long> S2 = getSequence(i, j, b[i], b[j]);
            vector<long long> S(S1.begin(), S1.end());
            S.insert(S.end(), S2.begin(), S2.end());
            vector<int> hash = vh.hash(S);
            mp[hash]++;
        }
    }
    map<long long, int> val;
    {
        for (int i = 2; i <= n; i++) {
            long long res = 1LL * i * (i - 1) / 2;
            val[res] = i;
        }
    }
    int ans = INT_MAX;
    for (auto& [_, cnt] : mp) {
        ans = min(ans, n - val[cnt]);
    }
    cout << ans << '\n';
    
    return 0;
}