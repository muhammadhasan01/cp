#include <bits/stdc++.h>

using namespace std;

const int BLOCK = 400;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<long long>> P(BLOCK + 1, vector<long long>(n + 1));
    vector<vector<long long>> S(BLOCK + 1, vector<long long>(n + 1));
    for (int b = 1; b <= BLOCK; b++) {
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            P[b][i] = (i - b <= 0 ? 0LL : P[b][i - b]) + a[i] * cnt;
            S[b][i] = (i - b <= 0 ? 0LL : S[b][i - b]) + a[i];
            if (i % b == 0) {
                ++cnt;
            }
        }
    }
    
    auto answer = [&](int s, int d, int k) -> long long {
        if (d > BLOCK) {
            long long ret = 0;
            for (int i = s, cnt = 1; cnt <= k; cnt++, i += d) {
                ret += a[i] * cnt;
            }
            return ret;
        }
        int j = s + d * (k - 1);
        long long pre = P[d][j] - (s - d <= 0 ? 0LL : P[d][s - d]);
        long long sum = S[d][j] - (s - d <= 0 ? 0LL : S[d][s - d]);
        int pos = (s + d - 1) / d;
        return pre - sum * (pos - 1);
    };

    for (int i = 0; i < q; i++) {
        int s, d, k;
        cin >> s >> d >> k;
        cout << answer(s, d, k) << " \n"[i == q - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}