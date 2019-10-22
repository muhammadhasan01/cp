// author : donbasta
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define foru(i,a,b) for(int i = (int) a; i < (int) b; i++)
#define ford(i,a,b) for(int i = (int) a; i > (int) b; i--)
#define fors(i,n) for(int i = 0; i < n; i++)
#define fill(a,b) memset(a, (b), sizeof(a))
#define pii pair<int, int>
#define pll pair<long long, long long>
const int MAXN = 100000;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m,n,a[MAXN+5];
	cin >> m;
	int M=m;
	while(m--){
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		sort(a+1, a+1+n);
		int cur_time=0, prio_job=1, ans=0;
		while(prio_job <=n){
			while( 2*a[prio_job]-cur_time < a[prio_job] && prio_job<=n) prio_job++;
				if(prio_job<=n){
					cur_time += a[prio_job];
					prio_job++;
					ans++;
				}
		}
		cout << "Case #" << M-m << ": " << ans << "\n";

	}

}
