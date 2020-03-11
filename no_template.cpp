#include <bits/stdc++.h>

using namespace std;

int n;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int x;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += (1LL) * x;
	}
	cout << sum << '\n';

	return 0;
}