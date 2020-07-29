#include <iostream>
using namespace std;

struct city{
	int x,y;
};

int tc, n, lis[1003];
city a[1003];

bool cmpr(city a, city b){
	if(a.y == b.y){
		return a.x < b.x;
	}
	return a.y < b.y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;
	while(tc--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i].x;
		}
		for(int i=0;i<n;i++){
			cin >> a[i].y;
		}
		for(int i=0;i<n;i++){
			lis[i] = 0;
			for(int j=0;j<i;j++){
				if(a[j].x <= a[i].x && lis[i] < 1+lis[j]){
					lis[i] = 1+lis[j];
				}
			}
		}
		cout << *max_element(lis,lis+n) << "\n";
	}

	return 0;
}
