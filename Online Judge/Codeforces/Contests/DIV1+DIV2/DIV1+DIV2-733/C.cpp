#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int n;
int a[N], b[N];
long long pre_a[N], pre_b[N];

long long get_mine(int x) {
    int m = n + x;
    int take = m - m / 4;
    int add = min(x, take);
    long long ret = 1LL * add * 100 + pre_a[max(0, take - add)];
    return ret;
}

long long get_alya(int x) {
    int m = n + x;
    int take = m - m / 4;
    return pre_b[min(n, take)];
}

bool can(int x) {
    return get_mine(x) >= get_alya(x);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n, greater<>());
    sort(b + 1, b + 1 + n, greater<>());
    for (int i = 1; i <= n; i++) {
        pre_a[i] = pre_a[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre_b[i] = pre_b[i - 1] + b[i];
    }
    int l = 0, r = INF, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}