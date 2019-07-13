#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
long long x[N],y[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> x[i];
    }
    for(int i=1;i<=m;i++){
        cin >> y[i];
    }

    int l1 = 1, l2 = 1, ans = 0;
    long long sum1 = x[l1], sum2 = y[l2];
    while(l1 <= n && l2 <= m){
        if(sum1 == sum2){
            ans++;
            l1++, l2++;
            sum1 = x[l1], sum2 = y[l2];
        }else if(sum1 > sum2){
            l2++;
            sum2 += y[l2];
        }else if(sum1 < sum2){
            l1++;
            sum1 += x[l1];
        }
    }
    cout << ans << '\n';

    return 0;
}
