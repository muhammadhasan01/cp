#include <bits/stdc++.h>

using namespace std;

long long egcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    long long x1, y1, d = egcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// Function to find module invers a
// ax + by = 1 => ax = 1 (mod b), so our task is to find x
long long modinverse1(long long a, long long b) {
    long long x, y;
    long long g = egcd(a, b, x, y);
    assert(g == 1);
    long long res = (x % b + b) % b;
    return res;
}

void solve() {
    long long k, l, m, n;
    cin >> k >> l >> m >> n;
    long long kk = k;
    long long nn = n;
    long long mm = m;
    long long g = __gcd(k, m);
    if (n % g != 0) {
        cout << "TIDAK" << '\n';
        return;
    }
    k /= g;
    m /= g;
    n /= g;
    // m * x = n (mod k)
    // 0 <= x <= l
    long long cur = modinverse1(m, k);
    long long x = (n * cur) % k;
    // k * mul + x <= l
    if (x > l) {
        cout << "TIDAK" << '\n';
        return;
    }
    long long mul = (l - x) / k;
    long long res = k * mul + x;
    long long rem = res * mm - nn;
    if (res <= 0 || rem <= 0 || rem % kk != 0) {
        cout << "TIDAK" << '\n';
        return;
    }
    cout << "YA " << res << '\n';
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