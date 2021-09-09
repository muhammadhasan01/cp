#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long r, b, d;
    cin >> r >> b >> d;
    if (r > b) {
        swap(r, b);
    }
    long long a = 1 + d;
    long long dif = d + 1;
    long long c = a + dif * (r - 1);
    cout << (b <= c ? "YES" : "NO") << '\n';
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