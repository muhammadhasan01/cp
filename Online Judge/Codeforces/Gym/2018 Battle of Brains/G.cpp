#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9 + 7;

long long pre[N];

long long get(int l, int r) {
    assert(r >= l);
    long long ret = pre[r] % M;
    if (l > 0) {
        ret = (ret - pre[l - 1]) % M;
        ret = (ret % M + M) % M;
    }
    return ret % M;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        a[i] = (int) cc;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int lft = n - i;
        long long add = get(lft, lft + i);
        long long sub = get(0, i);
        long long val = ((add - sub) % M + M) % M;
        val = (val * a[i]) % M;
        ans = (ans + val) % M;
    }
    cout << (ans % M + M) % M << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long sum = 0;
    for (int i = 1; i < N; i++) {
        sum = (sum + i) % M;
        pre[i] = (pre[i - 1] + sum) % M;
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case " << T << ": ";
        solve();
    }

    return 0;
}