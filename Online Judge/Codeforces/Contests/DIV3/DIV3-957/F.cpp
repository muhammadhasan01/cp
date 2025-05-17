#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> divisors[N];

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (x % a[i] != 0) {
            a[i] = 1;
        }
    }
    int m = (int) divisors[x].size();
    vector<bool> can(m);
    can[0] = true;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) {
            for (int j = m - 1, k = m - 1; j >= 0; j--) {
                if (can[j]) {
                    continue;
                }
                if (divisors[x][j] % a[i] == 0) {
                    int res = divisors[x][j] / a[i];
                    while (divisors[x][k] > res) {
                        k--;
                    }
                    if (divisors[x][k] == res && can[k]) {
                        can[j] = true;
                    }
                }
            }
        }
        if (can[m - 1]) {
            ++ans;
            i--;
            for (int j = 0; j < m; j++) {
                can[j] = false;
            }
            can[0] = true;
        }
    }
    cout << ans + 1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
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