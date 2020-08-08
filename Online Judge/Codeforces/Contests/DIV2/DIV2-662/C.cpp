#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int maxi, num;
int cnt[N];

void init() {
    for (int i = 1; i <= n; i++) {
        cnt[i] = 0;
    }
}

bool can(int x) {
    long long last = 1 + (1LL) * (maxi - 2) * (x + 1);
    return ((long long) n - last - num >= (long long) x);
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ++cnt[x];
    }
    maxi = 0;
    for (int i = 1; i <= n; i++) {
        maxi = max(maxi, cnt[i]);
    }
    num = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == maxi) ++num;
    }
    int l = 0, r = n - 2, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}