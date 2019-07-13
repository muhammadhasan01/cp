#include<bits/stdc++.h>
using namespace std;

const int N = 35;
int n;
long long c[N], l;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for(int i=0;i<n;i++){
        cin >> c[i];
        if(i>0)c[i] = min(c[i],2*c[i-1]);
    }
    long long ans = 4e18, sum = 0;
    for(int i=n-1;i>=0;i--){
        long long cost = l / (1<<i);
        sum += cost * c[i];
        l -= cost << i;
        ans = min(ans, sum + (l > 0) * c[i]);
    }
    cout << ans << "\n";

    return 0;
}
