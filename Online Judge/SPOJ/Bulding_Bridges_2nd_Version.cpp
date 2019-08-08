#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+5;
int tc, n;
const long double eps = 1e-9;
long double h[N], c[N];

long double f(long double x){
    long double ret = 0;
    for(int i=1;i<=n;i++){
        ret += (long double)c[i] * abs(h[i] - x);
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
        long double l = 1e9, r = -1;
        for(int i=1;i<=n;i++){
            cin >> h[i];
            l = min(l,h[i]);
            r = max(r,h[i]);
        }
        for(int i=1;i<=n;i++){
            cin >> c[i];
        }
        while(r - l > eps){
            long double m1 = l + (r - l)/3 , m2 = r - (r - l)/3;
            if(f(m1) > f(m2)){
                l = m1;
            }else{
                r = m2;
            }
        }
        long long k1 = floor(l), k2 = ceil(l);
        long long r1 = 0, r2 = 0;
        for(int i=1;i<=n;i++){
            r1 += (long long)c[i] * abs(h[i] - k1);
            r2 += (long long)c[i] * abs(h[i] - k2);
        }
        cout << min(r1,r2) << '\n';
    }


    return 0;
}
