#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    long long rem = m % k;
    if (a1 >= rem) {
        ak += (a1 - rem) / k;
        m -= rem;
        cout << max(0LL, m / k - ak) << '\n';
        return;
    }
    long long res = rem - a1;
    m -= rem;
    res += max(0LL, m / k - ak);
    cout << res << '\n';
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