#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
int tc, n;
long long h[N], c[N];

long long f(long long x){
    long long ret = 0;
    for(int i=1;i<=n;i++){
        ret += (long long)c[i] * abs(h[i] - x);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n;
        long long l = 1e9, r = -1;
        for(int i=1;i<=n;i++){
            cin >> h[i];
            l = min(h[i], l);
            r = max(h[i], r);
        }
        for(int i=1;i<=n;i++){
            cin >> c[i];
        }

        while(r - l >= 3){
            long long m1 = l + (r - l)/3;
            long long m2 = r - (r - l)/3;
            if(f(m1) > f(m2)){
                l = m1;
            }else{
                r = m2;
            }
        }
        long long ans = 1e18;
        for(long long i=l;i<=r;i++){
            ans = min(ans, f(i));
        }
        cout << ans << '\n';
    }

    return 0;
}
