// author: donbasta
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+69;

int n,k,sum;
int pre[N], mx[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		pre[i] = pre[i-1] + x;
	}

	if(2*k >= n){
		cout << pre[n] << "\n";
	} else {
		int ans = 0;
		for(int i=k; i<=n; i++){
			mx[i] = max(mx[i-1], pre[i]-pre[i-k]);
		}
		for(int i=2*k; i<=n; i++){
			ans = max(ans, mx[i-k]+pre[i]-pre[i-k]);
		}
		cout << ans << "\n";
	}

}