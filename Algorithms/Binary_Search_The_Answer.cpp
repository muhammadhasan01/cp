#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.spoj.com/problems/AGGRCOW/

// f(x) returns 1 if the cows could have a distance at least x otherwise returns 0
int f(int x,vector<int> pos,int n,int c){
    int cowsplaced = 1, lastpos = pos[0];
    for(int i=1;i<n;i++){
        if(pos[i]-lastpos >= x){
        cowsplaced++;
        if(cowsplaced == c){return 1;}
        lastpos = pos[i];
        }
    }
    return 0;
}

int main() {
    int T;cin>>T;
    while(T--){
    int n,k,temp;cin>>n>>k;
    vector<int> a;
    for(int i=0;i<n;i++){cin>>temp;a.push_back(temp);};
	sort(a.begin(),a.end());
	// a[n] = {1,2,4,8,9}
	int left = 0, right = a[n-1]-a[0]+1, mid; // right is initialized as the furthest distance plus 1
	while(right-left > 1){
        mid = (left+right)/2;
        // Invariant : f(left) is always 1 and f(right) is always 0
        if(f(mid,a,n,k)){
            left = mid;
        }else{
            right = mid;
        }
	}
	cout << left << "\n";
	a.clear();
    }
}
// source : https://www.codementor.io/rishabhdaal/solving-problems-binary-search-interview-questions-du1089cq6
