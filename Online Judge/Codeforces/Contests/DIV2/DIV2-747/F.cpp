#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long s, n, k;
    cin >> s >> n >> k;
    if (s == k) {
        cout << "YES" << '\n';
        return;
    }
    long long ans = (s / (2 * k)) * k;
    long long rem = s % (2 * k);
    ans += min(rem + 1, k);
    cout << (n + 1 > ans ? "YES" : "NO") << '\n';
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