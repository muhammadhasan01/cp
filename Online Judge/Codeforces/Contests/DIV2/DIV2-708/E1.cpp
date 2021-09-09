#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int res[N];
int last_prime[N];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 1);
    map<int, int> last;
    for (int i = 1, pos = 0; i <= n; i++) {
        pos = max(pos, last[res[a[i]]]);
        last[res[a[i]]] = i;
        dp[i] = 1 + dp[pos];
    }
    cout << dp[n] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (last_prime[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            last_prime[j] = i;
        }
    }
    for (int i = 1; i < N; i++) {
        int x = i;
        res[i] = 1;
        while (x > 1) {
            int pr = last_prime[x];
            int bit = 0;
            while (x % pr == 0) {
                x /= pr;
                bit ^= 1;
            }
            if (bit) {
                res[i] *= pr;
            }
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}