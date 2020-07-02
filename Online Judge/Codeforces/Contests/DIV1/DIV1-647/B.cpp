#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int K = 30;
const long long M = 1e9 + 7;

int tc;
int n, p;
int k[N];

long long modpow(long long x, long long y, long long p) {
    long long ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> p;
        for (int i = 1; i <= n; i++) {
            cin >> k[i];
        }
        if (p == 1) {
            cout << (n & 1) << '\n';
            continue;
        }
        sort(k + 1, k + 1 + n, greater<int>());
        unordered_map<int, int> cnt;
        int maks = k[1];
        int l = 1, r = 1;
        cnt[maks]--;
        for (int i = 2; i <= n; i++) {
            cnt[k[i]]++;
            r = i;
            for (int t = max(0, maks - K); t <= maks - 1; t++) {
                cnt[t + 1] += cnt[t] / p;
                cnt[t] %= p;
            }
            if (cnt[maks] == 0) {
                ++i;
                maks = k[i];
                l = r = i;
                cnt[maks]--;
            }
        }
        long long res = 0;
        if (l <= n) {
            for (int i = l; i <= r; i++) {
                if (i == l) {
                    res = (res + modpow(p, k[i], M)) % M;
                } else {
                    res = ((res - modpow(p, k[i], M)) + M) % M;
                }
            }
        }
        cout << (res % M + M) % M << '\n';
    }

    return 0;
}