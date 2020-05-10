// author : donbasta
#include <bits/stdc++.h>

using namespace std;

const int N = 4e3+69;
const long double PI = acos(-1);

int n;
long long gr[N], sum, ans=1e18;
struct point {
	long long x,y;
	point() {x=y=0;}
	point(int xx, int yy) {x=xx; y=yy;} 
} pt[N];

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);

 cin >> n;
 for(int i=0; i<n; i++){
 	long long x,y,z;
 	cin >> x >> y >> z;
 	pt[i] = point(x,y);
 	gr[i] = z;
 	sum += gr[i];
 }

 for(int i=0; i<n; i++){
 	vector<pair<long double, long long>> ve;
 	vector<long double> pre(n);
 	for(int j=0; j<n; j++){
 		if(j==i) continue;
 		//itung nilai sudut disini
 		long double kosinus = (long double) (pt[j].x-pt[i].x) / hypot(pt[j].x-pt[i].x, pt[j].y-pt[i].y);
 		long double angle = acos(kosinus);
 		if(pt[j].y-pt[i].y<0){
  		angle = 2*PI - angle;
  	}
 		ve.push_back(make_pair(angle, gr[j]));
 	}
 	sort(ve.begin(),ve.end());
 	pre[0] = 0;
 	for(int j=1; j<n; j++){
 		pre[j] = pre[j-1] + ve[j-1].second;
 	}
 	for(int j=0; j<(int)ve.size(); j++){
 		long double angle = ve[j].first;
 		long double batas = angle + PI;
 		int idx;
 		long long side1;
 		if(batas < 2*PI){
 			idx = lower_bound(ve.begin(),ve.end(),make_pair(batas,0ll))-ve.begin();
 			// idx = (idx + (n-2)) % (n-1); //decrement idx
 			side1 = pre[idx]-pre[j+1];
 		} else {
 			batas -= 2*PI;
 			idx = lower_bound(ve.begin(),ve.end(),make_pair(batas,0ll))-ve.begin();
 			side1 = pre[idx]+pre[n-1]-pre[j+1];
 		}
 		long long side2 = sum-side1-gr[i]-ve[j].second;
 		long long dif = abs(side1-side2);
 		ans = min(ans, dif);
 	}
 }

 cout << ans << "\n";

}