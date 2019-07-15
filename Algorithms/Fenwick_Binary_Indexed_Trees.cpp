#include<bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/

int BIT[1000], a[1000], n;

void update(int x, int val){
    for(; x<=n ; x+=x&-x){
        BIT[x] += val;
    }
}

void update2(int x, int val){
    for(; x<0 ; x|=(x+1)){
        BIT[x] += val;
    }
}

int query(int x){
    int sum = 0;
    for(; x>0 ; x-=x&-x){
        sum += BIT[x];
    }
    return sum;
}

int query2(int x){
    int sum = 0;
    for(;x>=0;x=(x&(x+1))-1){
        sum += BIT[x];
    }
    return sum
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        update(i,a[i]);
    }
    cout << "Sum of the first element is " << query(10) << "\n";
    cout << "Sum of the range[2,7] is " << query(7)-query(2-1) << "\n";

    return 0;
}
