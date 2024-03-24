#include <bits/stdc++.h>

using namespace std;

const int K = 60;

void solve() {
    long long a, b, r;
    cin >> a >> b >> r;
    if (a < b) {
        swap(a, b);
    }
    bool first = false;
    long long res = 0;
    for (int i = K; i >= 0; i--) {
        bool ba = a & (1LL << i);
        bool bb = b & (1LL << i);
        if (ba == bb) {
            continue;
        }
        if (ba && !bb) {
            if (!first) {
                first = true;
                continue;
            }
            long long cur = res + (1LL << i);
            if (cur > r) {
                continue;
            }
            res = cur;
        }
    }
    a = (a ^ res);
    b = (b ^ res);
    if (a < b) {
        swap(a, b);
    }
    cout << a - b << '\n';
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