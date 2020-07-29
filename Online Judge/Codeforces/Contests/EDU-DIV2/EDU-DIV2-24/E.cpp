#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long k;
vector<int> primes, occ;
vector<int> pre[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (long long i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            int cnt = 0;
            while (k % i == 0) {
                ++cnt;
                k /= i;
            }
            primes.emplace_back(i);
            occ.emplace_back(cnt);
        }
    }
    if (k > 1) {
        primes.emplace_back(k);
        occ.emplace_back(1);
    }
    int len = primes.size();
    pre[0].assign(len, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pre[i].resize(len);
        for (int j = 0; j < len; j++) {
            int cnt = 0;
            while (x % primes[j] == 0) {
                ++cnt;
                x /= primes[j];
            }
            pre[i][j] = pre[i - 1][j] + cnt;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int hgh = i;
        for (int j = 0; j < len; j++) {
            int l = 1, r = i, at = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[i][j] - pre[mid - 1][j] >= occ[j]) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            hgh = min(hgh, at);
        }
        ans += (1LL) * hgh;
    }
    cout << ans << '\n';

    return 0;
}