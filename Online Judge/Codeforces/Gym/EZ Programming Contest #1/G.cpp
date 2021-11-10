#include <bits/stdc++.h>

using namespace std;

int ans[15] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
int pref[7] = {888, 108, 188, 200, 208, 288, 688};

void solve() {
	int n;
	cin >> n;
	if (n < 15) {
	    cout << ans[n];
	}
	else {
	    cout << pref[n % 7];
	    for (int i = 0; i < (n - 1) / 7 - 2; i++) {
	        cout << 8;
	    }
	}
	cout << ' ';
	cout << (n % 2 ? 7 : 1);
	for (int i = 0; i < n / 2 - 1; i++) {
	    cout << 1;
	}
	cout << endl;
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