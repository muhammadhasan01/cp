#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--){
        int n; long long k;
        cin >> n >> k;
        long long mini = 1e18, maxi = -1;
        for(int i=1;i<=n;i++){
            long long x; cin >> x;
            mini = min(mini,x);
            maxi = max(maxi,x);
        }
        long long ans = mini + k;
        cout << (ans < maxi - k ? -1 : ans) << '\n';
    }

    return 0;
}
