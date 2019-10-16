#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N], bit[N], f[N], f2[N];
map<int, int> m;

void add(int x, int val) {
    for (; x <= n; x += x & -x) bit[x] += val;
}

int query(int x) {
    int ret = 0;
    for (; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (m[a[i]] == 0) m[a[i]] = ++cnt;
        f[m[a[i]]]++;
    }
    long long ans = 0;
    for (int i = n; i >= 2; i--) {
        int c1 = m[a[i]], c2 = m[a[i - 1]];
        int suf = ++f2[c1];
        int pre = f[c2] - f2[c2];
        add(suf, 1);
        ans += (1LL) * (query(pre - 1));
    }
    cout << ans << '\n';

    return 0;
}
