#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, q;
int cnt[N];
long long dp[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            cnt[j]++;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        dp[cnt[x]] += x;
    }
    for (int i = 1; i < N; i++) {
        dp[i] += dp[i - 1];
    }
    cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << dp[x] << '\n';
    }
    
    return 0;
}