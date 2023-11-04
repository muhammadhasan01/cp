#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> rates(n + 1);
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        rates[i] = rates[i - 1] + a[i];
        pre[i] = max(pre[i - 1], rates[i]);
    }
    long long best = -INF;
    long long k = 0;
    for (int i = 1; i <= n; i++) {
        long long cur = pre[i - 1] - rates[i];
        if (cur > best) {
            best = cur;
            k = pre[i - 1];
        }
    }
    cout << k << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}