#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
int a[N];
vector<int> bit[N];

void add(int i, int val){
    for(;i<=n;i+=i&-i){
        bit[i].push_back(val);
    }
}

int query(int i, int x){
    long long sum = 0;
    for(;i>0;i-=i&-i){
        int pos = lower_bound(bit[i].begin(),bit[i].end(),x) - bit[i].begin();
        sum += bit[i].size() - pos;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        add(i,a[i]);
    }
    long long ans = 0;
    for(int i=1;i<=n;i++)sort(bit[i].begin(),bit[i].end());
    for(int i=1;i<=n;i++){
        if(a[i]<=i)continue;
        ans += query(min(n,a[i]),i) - query(i,i);
    }
    cout << ans << '\n';

    return 0;
}
