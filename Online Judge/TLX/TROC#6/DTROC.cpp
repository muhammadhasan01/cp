#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n,q;
long long ans;
long long bit[35];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        int k = 0;
        while(x > 0){
            if(x&1)bit[k]++;
            k++;
            x/=2;
        }
    }

    for(int i=0;i<=33;i++){
        long long c1 = bit[i], c2 = n - bit[i];
        long long p = (1<<i)%MOD;
        for(int j=1;j<=q;j++){
            long long t1 = (2 * c1 * c2)%MOD;
            long long t2 = ((c1 * c1)%MOD + (c2 * c2)%MOD)%MOD;
            c1 = t1, c2 = t2;
        }
        long long res = (c1 * p)%MOD;
        ans += res; ans %= MOD;
    }

    cout << (ans%MOD + MOD)%MOD << "\n";

    return 0;
}
