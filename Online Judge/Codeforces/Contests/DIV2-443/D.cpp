#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long n, k, m;
long long ans;
int a[N], s[N], f[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (k >= n) {
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i + 1]) {
                flag = false;
                break;
            }
        }
        ans = n * m;
        if (flag) ans %= k;
        cout << ans << '\n';
        return 0;
    }
    int top = 0;
    for (int i = 1; i <= n; i++) {
        s[++top] = a[i];
        f[top] = 1;
        if (top > 1 && s[top] == s[top - 1]) {
            f[top] = 1 + f[top - 1];
        }
        if (f[top] == k) top -= k;
    }
    if (top == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int L = 1, R = top;
    while (s[L] == s[R] && L != R) {
        int l = L, r = R, cnt = 0;
        while (s[l] == s[L] && l < r && cnt < k) ++l, ++cnt;
        while (s[r] == s[R] && l < r && cnt < k) --r, ++cnt;
        if (cnt == k) L = l, R = r, ans += k;
        else break;
    }
    bool flag = true;
    for (int i = L + 1; i <= R; i++) {
        if (s[i] != s[i - 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        long long cur = (1LL) * (R - L + 1) * m;
        cur %= k;
        if (cur == 0) ans = 0;
        else ans = ans + cur;
    } else {
        ans = ans + (1LL) * (R - L + 1) * m;
    }
    cout << ans << '\n';

    return 0;
}