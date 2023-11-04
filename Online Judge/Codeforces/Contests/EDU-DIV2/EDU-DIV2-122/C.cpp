#include <bits/stdc++.h>

using namespace std;

long long ceil(long long x, long long y) {
    return (x + y - 1) / y;
}

void solve() {
    long long hc, dc;
    long long hm, dm;
    long long k, w, a;
    cin >> hc >> dc;
    cin >> hm >> dm;
    cin >> k >> w >> a;
    for (long long x = 0; x <= k; x++) {
        long long y = k - x;
        long long H = hc + a * x;
        long long D = dc + w * y;
        if (ceil(hm, D) <= ceil(H, dm)) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << '\n';
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