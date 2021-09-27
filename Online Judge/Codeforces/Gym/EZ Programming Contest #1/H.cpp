#include <bits/stdc++.h>

using namespace std;

long double f(long long x) {
	if (x == 0) {
        return 0;
    }
	if (x <= 60) {
        return (long double) 2 - (long double) 1 / (1LL << (x - 1));
    }
	return (long double) 2;
}

void solve() {
	int n;
	cin >> n;
	long long a;
	long double res = 0.0;
	for (int i = 0; i < n; i++) {
	    cin >> a;
	    res += f(a);
	}
	cout << fixed << setprecision(12) << res << endl;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}