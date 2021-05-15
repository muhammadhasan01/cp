#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e9;

vector<long long> pre;

void solve() {
    long long n;
    cin >> n;
    auto it = lower_bound(pre.begin(), pre.end(), n);
    long long ans = it - pre.begin() + 1;
    if (*it > n) ans--;
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < 10; i++) {
        long long x = i;
        while (x < INF) {
            pre.emplace_back(x);
            x = 10 * x + i;
        }
    }
    sort(pre.begin(), pre.end());

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}