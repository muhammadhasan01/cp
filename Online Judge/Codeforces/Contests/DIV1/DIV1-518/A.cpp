#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = 2e2 + 5;
const int L = ceil(log2(N)) + 2;
const int M = 998244353;

int n;
int a[N];
long long dp[K][K][L];

void dismiss() {
    puts("0");
    exit(0);
}

int F(int x) {
    return x * (x + 1) / 2;
}

long long process(int l, int r) {
    if (r == l + 1) return 1LL;
    if (r == l + 2) return min(a[l], a[r]);
    if (r == l + 3) {
        int x = a[l], y = a[r];
        if (x > y) swap(x, y);
        return x * y + F(y - x) + (200 - y);
    }
    int len = r - l;
    int x = 1;
    while (2 * x <= len) x <<= 1;
    bool flag = (x == len);
    if (flag) {
        x /= 2;
        if (dp[a[l]][a[r]][len] != -1)
            return dp[a[l]][a[r]][len];
    }
    long long ret = 0;
    for(int val = 1; val <= 100; val++) {
        a[l + x] = val;
        ret = (ret + process(l, l + x) * process(l + x, r)) % M;
    }
    if (flag) dp[a[l]][a[r]][len] = ret;
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            flag = false;
            break;
        }
    }
    if (flag) dismiss();
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == -1 || a[i] == -1 || a[i + 1] == -1) continue;
        if (a[i] > max(a[i - 1], a[i + 1])) {
            flag = true;
            break;
        }
    }
    if (flag) dismiss();
    memset(dp, -1, sizeof(dp));
    a[0] = a[n + 1] = 1;
    long long ans = 1;
    int last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] == -1) continue;
        ans = (ans * process(last, i)) % M;
        last = i;
    }
    cout << ans << '\n';

    return 0;
}