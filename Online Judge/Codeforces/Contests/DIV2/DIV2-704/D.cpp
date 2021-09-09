#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, k;
    cin >> a >> b >> k;
	int n = a + b;
    string s(n, '0'), p(n, '0');
	if (k == 0) {
		for (int i = 0; i < b; i++) {
			s[i] = p[i] = '1';
        }
        cout << "Yes" << '\n';
        cout << s << '\n';
        cout << p << '\n';
		return 0;
	}
	if (a == 0 || b == 1) {
		cout << "No" << '\n';
		return 0;
	}
	if (k >= n - 1) {
        cout << "No" << '\n';
		return 0;
	}
	s[0] = p[0] = '1';
	s[1] = p[1 + k] = '1';
	b -= 2;
	for (int i = 2; b > 0 && i < n; i++) {
		if (i == 1 + k) {
            continue;
        }
		s[i] = p[i] = '1';
		b--;
	}
    cout << "Yes" << '\n';
    cout << s << '\n';
    cout << p << '\n';
    
    return 0;
}