// author : donbasta
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = ((a + 1) * (b + 1) / (c + 1)) - 1;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}