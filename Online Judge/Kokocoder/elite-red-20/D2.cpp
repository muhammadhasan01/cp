#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
 
ll t, N, D[200010], total, a;
set<int> him;
 
 
 
int main() {
	cin >> t;
	while(t--){
		him.clear();
		bool gabisa = false;
		cin >> N;
		for(int i = 1;i<= 2*N; i++){
			cin >> a;
			him.insert(a);
		}
		// for(auto i : him){
		// 	cout << i << ' ';
		// }
		// cout << endl;
		if(him.size() != N){
			cout << "NO" << endl;
			continue;
		}
		else{
			total = 0;
			int M = 0;
			for(auto i : him){
				D[++M] = i;
			}
			sort(D+1, D+M+1);
			for(int i = M; i>= 1; i--){
				D[i] -= total;
				if( D[i] <= 0 || D[i]%(2*i) != 0){
					gabisa = true;
					break;
				}
				total+= (D[i]/(i));
			}
			if(gabisa){
				cout <<  "NO" << endl;
			}
			else{
				cout << "YES" << endl;
			}
		}
	}
}