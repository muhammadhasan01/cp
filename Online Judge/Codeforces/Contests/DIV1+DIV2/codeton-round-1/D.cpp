#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e18 + 5;
const int K = 61;

void solve() {
    long long n;
    cin >> n;
    for (int x = 1; x <= K; x++) {
        long long cur = (1LL << x);
        if (n % cur == cur / 2) {
            if (INF / (cur + 1) <= cur / 2) {
                continue;
            }
            long long mn = cur * (cur + 1) / 2;
            if (n >= mn) {
                cout << cur << '\n';
                return;
            }
        }
    }
    long long original = n;
    while (n % 2 == 0) {
        n /= 2;
    }
    if (n == 1) {
        cout << -1 << '\n';
        return;
    }
    if (INF / (n + 1) <= n / 2) {
        cout << -1 << '\n';
        return;
    }
    long long mn = n * (n + 1) / 2;
    if (original >= mn) {
        cout << n << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}