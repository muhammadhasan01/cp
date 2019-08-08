#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const long double eps = 1e-9;
int n;
long double k, s[N], d[N];

long double f(long double x){
    long double k1 = 1e18, k2 = -1;
    for(int i=1;i<=n;i++){
        long double cur = d[i] + s[i] * x;
        k1 = min(k1,cur);
        k2 = max(k2,cur);
    }
    return k2 - k1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> s[i] >> d[i];
    }
    long double l = 0, r = k, ans = 1e18;
    while(r - l > eps){
        long double m1 = l + (r - l)/3;
        long double m2 = r - (r - l)/3;
        if(f(m1) < f(m2)){
            r = m2;
        }else{
            l = m1;
        }
    }
    cout << fixed << setprecision(6) << f(l) << '\n';

    return 0;
}
