// author : donbasta
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a, b, c, p, q, r;
	cin >> a >> b >> c;
	cin >> p >> q >> r;
	int ans = max(0, p - a) + max(0, q - b) + max(0, r - c);
	cout << ans << '\n';
	return 0;
}