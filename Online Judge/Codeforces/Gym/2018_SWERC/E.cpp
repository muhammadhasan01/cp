// author : donbasta
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+69;

int p, sum = 0;
string places[N];
int maks[N], mini[N], rat[N];
int er1, er2;

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0), cout.tie(0);

 cin >> p;
 for(int i=0; i<p; i++){
 	cin >> places[i] >> rat[i];
 	sum += rat[i];
 }

 bool ok = true;
 for(int i=0; i<p; i++){
 	int dif1 = 49 * (p-1);
 	int dif2 = 50 * (p-1);
 	int offset = 100*100 - 100*sum;

 	mini[i] = max(offset-dif1, -50);
 	maks[i] = min(offset+dif2, 49);

 	if(mini[i] > maks[i]){
 		ok = false;
 	}

 	mini[i] = max(100*rat[i]+mini[i],0);
 	maks[i] = min(100*rat[i]+maks[i],10000);
 }

 if(!ok){
 	cout << "IMPOSSIBLE" << "\n";
 } else {
 	for(int i=0; i<p; i++){
 		double x = (double) mini[i] / 100.0;
 		double y = (double) maks[i] / 100.0;
 		cout << fixed << setprecision(2) << places[i] << " " << x << " " << y;
 		cout << "\n";
 	}
 }

}
