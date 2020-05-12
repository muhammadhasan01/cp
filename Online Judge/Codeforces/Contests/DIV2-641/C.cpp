#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N], pre[N], suf[N];
long long b[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = __gcd(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }
    for (int i = 1; i <= n; i++) {
        b[i] = __gcd(pre[i - 1], suf[i + 1]);
    }
    long long ans = b[1];
    for (int i = 2; i <= n; i++) {
        ans = (ans * b[i]) / __gcd(ans, b[i]);
    }
    cout << ans << '\n';

    return 0;
}