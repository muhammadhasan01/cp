#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int inf = 1e6;
int n;
long long ar[N];

int check(long long a, long long b){
    int ret = inf, cnt = 0;
    b = b - a;
    bool ok = true;
    for(int i=1;i<=n;i++){
        long long cur = a + b * (long long)(i - 1);
        long long temp = abs(cur - ar[i]);
        if(temp <= 1){
            cnt += temp;
        }else{
            ok = false;
        }
        if(!ok)break;
    }
    if(ok){
        ret = min(ret,cnt);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
    }

    if(n == 1){
        cout << 0 << '\n';
        return 0;
    }

    int ans = inf;
    for(auto e : {-1,0,1})
        for(auto el : {-1,0,1})
            ans = min(ans, check(ar[1] + e, ar[2] + el));

    if(ans == inf)ans = -1;

    cout << ans << '\n';


    return 0;
}
