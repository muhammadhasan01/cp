#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<long long>> result(2, vector<long long>(n));
    for (int st : {0, 1}) {
        long long sum = 0;
        long long mini = INF;
        for (int i = st, cnt = 1; i < n; i += 2, cnt++) {
            mini = min(mini, c[i]);
            sum += c[i];
            result[st][i] = sum + mini * (n - cnt);
        }
    }
    long long ans = INF;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            long long cur = result[1][i] + result[0][i - 1];
            ans = min(ans, cur);
        } else {
            long long cur = result[0][i] + result[1][i - 1];
            ans = min(ans, cur);
        }
    }
    cout << ans << '\n';
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