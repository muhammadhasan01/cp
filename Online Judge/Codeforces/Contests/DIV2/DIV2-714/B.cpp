#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 1e9 + 7;

int n;
int a[N];
int fact[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int AND = a[1];
    for (int i = 2; i <= n; i++) {
        AND = (AND & a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == AND) {
            ++cnt;
        }
    }
    if (cnt <= 1) {
        cout << 0 << '\n';
        return;
    }
    long long ans = 1LL * cnt * (cnt - 1);
    ans %= M;
    ans = (ans * fact[n - 2]) % M;
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        long long res = 1LL * fact[i - 1] * i;
        fact[i] = (res % M);
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}