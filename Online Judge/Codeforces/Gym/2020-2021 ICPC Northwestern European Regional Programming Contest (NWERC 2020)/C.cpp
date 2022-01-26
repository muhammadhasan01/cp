#include <bits/stdc++.h>

using namespace std;

void solve() {
    long double n, k;
    long double s, d;
    cin >> n >> k >> s >> d;
    long double sn = n * s;
    long double sk = k * d;
    long double rem = sn - sk;
    long double avg = rem / (n - k);
    if (0 <= avg && avg <= 100) {
        cout << fixed << setprecision(12) << avg << '\n';
    } else {
        cout << "impossible" << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}