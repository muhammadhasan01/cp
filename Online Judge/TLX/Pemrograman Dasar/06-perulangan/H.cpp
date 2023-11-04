#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	if (i % k == 0) {
    		cout << '*';
		} else {
			cout << i;
		}
		cout << " \n"[i == n];
	}
    
	return 0;
}
