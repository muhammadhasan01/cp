#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 1e6 + 5;

int n;
char a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '*') num++;
    }

    auto F = [&](int pos) -> long long {
        long long ret = 0;
        for (int i = pos + 1; i <= n; i++) {
            if (a[i] == '*') {
                ret += (i - pos);
            }
        }
        for (int i = pos - 1; i >= 1; i--) {
            if (a[i] == '*') {
                ret += (pos - i);
            }
        }
        return ret;
    };

    int l = 1, r = n - num + 1;
    while (r - l >= 3) {
        int p1 = l + (r - l) / 3;
        int p2 = r - (r - l) / 3;
        if (F(p1) < F(p2)) {
            r = p1;
        } else {
            l = p2;
        }
    }
    long long ans = INF;
    for (int i = l; i <= r; i++) {
        ans = min(ans, F(i));
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