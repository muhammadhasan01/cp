#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;
const int K = 16;

int dp[N];
int bit[N];

void add(int x) {
    for ( ; x < N; x += x & -x) bit[x]++;
}

int get(int x) {
    int ret = 0;
    for ( ; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

int ask(int l, int r) {
    if (dp[r] == -1) {
        cout << "? " << l << " " << r << endl;
        int ret;
        cin >> ret;
        dp[r] = ret - get(r);
        return ret;
    }
    int ret = dp[r] + get(r);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));
    int n, t;
    cin >> n >> t;
    for (int it = 0; it < t; it++) {
        int k;
        cin >> k;
        if (it == 0) {
            for (int rep = K; rep <= n; rep += K) {
                ask(1, rep);
            }
        }
        int at = n;
        {
            int l = 1, r = n / K;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int len = mid * K;
                int ans = ask(1, len);
                if (ans + k > len) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                    at = len;
                }
            }
        }
        int l = max(1, at - K), r = at;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int ans = ask(1, mid);
            if (ans + k > mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                at = mid;
            }
        }
        cout << "! " << at << endl;
        add(at);
    }

    return 0;
}