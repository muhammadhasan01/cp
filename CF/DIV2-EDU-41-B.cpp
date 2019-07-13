#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int k,n;
int a[N],pref[N],pre[N],suf[N];
bool t[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> t[i];
        pre[i] = pre[i-1];
        if(t[i])pre[i] += a[i];
    }
    for(int i=n;i>=1;i--){
        suf[i] = suf[i+1];
        if(t[i])suf[i] += a[i];
    }
    int ans = 0;
    for(int i=1;i<=n-k+1;i++){
        int res = pref[i+k-1] - pref[i-1] + pre[i-1] + suf[i+k];
        ans = max(ans,res);
    }
    cout << ans << '\n';

    return 0;
}
