#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e18;
const long long K = 1e5 + 5;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
	long long ans = INF;
	for (long long mx = 1; mx <= min(K, b); mx++) {
		long long res = (mx - 1);
		res += (mx <= a ? a / mx + (a % mx != 0) : 1);
		res += b / mx + (b % mx != 0);
		ans = min(ans, res);
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