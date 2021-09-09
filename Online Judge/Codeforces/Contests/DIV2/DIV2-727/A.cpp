#include <bits/stdc++.h>

using namespace std;

long long ceil(long long a, long long b) {
    return (a + b - 1) / b;
}

long long F(long long x) {
    return x * (x + 1) / 2;
}

void solve() {
    long long n, x, t;
    cin >> n >> x >> t;
    long long lst = (n - 1) * x;
    long long fst = max(0LL, lst - t);
    fst = ceil(fst, x) * x;
    long long m = (lst - fst) / x;
    long long ans = F(m) + m * (fst / x);
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