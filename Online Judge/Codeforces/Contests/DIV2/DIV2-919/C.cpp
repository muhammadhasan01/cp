#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> divisors[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 1;
    for (int d : divisors[n]) {
        int G = 0;
        for (int i = 1; i <= d; i++) {
            int cur = 0;
            for (int j = i + d; j <= n; j += d) {
                cur = __gcd(cur, abs(a[j] - a[j - d]));
            }
            G = __gcd(G, cur);
        }
        if (G != 1) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i + i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}