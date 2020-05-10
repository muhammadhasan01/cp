// author : donbasta
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+69;

int x,y,n;
bool ada[N];
int mx[N], mn[N];

long long f(int a){
	long long res = 0;
	for(int i=0; i<x; i++){
		if(ada[i]){
			if(a<mn[i]) res += 2*1ll*abs(mx[i]-a);
			else if(a>mx[i]) res += 2*1ll*abs(mn[i]-a);
			else res += 2*1ll*abs(mx[i]-mn[i]);
		}
	}
	return res;
}

long long ternary_search(int l, int r){
	while(r-l>=3){
		int m1 = l + (r-l)/3;
		int m2 = r - (r-l)/3;
		long long f1 = f(m1);
		long long f2 = f(m2);
		if(f1 > f2){
			l = m1+1;
		} else {
			r = m2;
		}
	}
	long long mini = 1e15+69;
	for(;l<=r;l++){
		mini = min(mini,f(l));
	}
	return mini;
}

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);

 cin >> x >> y;
 cin >> n;

 for(int i=0; i<x; i++){
 	mn[i] = 1e5+69;
 }

 for(int i=0; i<n; i++){
 	int xx,yy;
 	cin >> xx >> yy;
 	ada[xx] = true;
 	mx[xx] = max(mx[xx], yy);
 	mn[xx] = min(mn[xx], yy);
 }

 long long ans = ternary_search(0,y-1);
 cout << ans+1ll*(x-1) << "\n";
}