#include <bits/stdc++.h>

using namespace std;

const int K = 9;

void solve() {
    int n;
    cin >> n;
    int mul = 1;
    int ans = 0;
    for (int rep = 0; rep < K; rep++) {
        if (mul > n) {
            break;
        }
        for (int i = 1; i <= 9; i++) {
            int cur = mul * i;
            if (cur <= n) {
                ++ans;
            }
        }
        mul = mul * 10;
    }
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