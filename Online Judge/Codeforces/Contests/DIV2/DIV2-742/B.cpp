#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int pre[N];

void solve() {
    int a, b;
    cin >> a >> b;
    int res = pre[a - 1];
    if (b == res) {
        cout << a << '\n';
        return;
    }
    int c = (res ^ b);
    int ans = a;
    if (a == c) {
        ans += 2;
    } else {
        ans += 1;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 1; i < N; i++) {
        pre[i] = (pre[i - 1] ^ i);
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}