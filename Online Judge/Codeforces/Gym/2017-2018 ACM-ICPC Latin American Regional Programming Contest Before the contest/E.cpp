// author : donbasta
#include <bits/stdc++.h>
using namespace std;

int modpow(int a, int b, int mod) {
	int res = 1;
	while(b) {
		if(b & 1)
			res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return res;
}

string s;
int n;
int poww[1069];
int dp[1069][1069];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s;
	cin >> n;

	reverse(s.begin(), s.end());
	int sz = (int) s.length();

	for(int i = 0; i < sz; i++) {
		poww[i] = modpow(10, i, n);
	}

	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			dp[i][j] = 10;
		}
	}

	if(s[0] == '?'){
		for(int j = 0; j < 10; j++) {
			if(sz == 1 && j == 0)
				continue;
			int dig = j % n;
			if(dig == 0 && sz == 1)
				dig = j;
			dp[0][j % n] = min(dp[0][j % n], dig);
		}
	} else {
		int dig = (s[0] - '0');
		dp[0][dig % n] = dig;
	}

	for(int i = 1; i < sz; i++) {
		if(s[i] != '?') {
			int dig = s[i] - '0';
			for(int j = 0; j < n; j++) {
				if(dp[i - 1][j] != 10){
					dp[i][(j + dig * poww[i]) % n] = dig;
				}
			}
		} else {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < 10; k++) {
					if(i == sz - 1 && k == 0)
						continue;
					if(dp[i - 1][j % n] != 10){
						int dig = k % n;
						if(k % n == 0 && i == sz - 1)
							dig = k;
						dp[i][(j + k * poww[i]) % n] = min(dp[i][(j + k * poww[i]) % n], dig);
					}
				}
			}
		}
	}

	string s;
	int cur = 0;
	for(int i = sz - 1; i >= 0; i--) {
		// cerr << i << " " << cur << "\n";
		if(dp[i][cur] == 10) {
			cout << '*' << "\n";
			return 0;
		}
		s += (char) (dp[i][cur] + 48);
		cur = (1LL * cur - 1LL * dp[i][cur] * poww[i]) % n;
		if(cur < 0)
			cur += n;
	}

	cout << s << "\n";
	return 0;

}