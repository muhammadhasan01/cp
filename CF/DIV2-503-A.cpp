#include<bits/stdc++.h>
using namespace std;

int n,h,a,b,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> a >> b >> k;
    for(int i=1;i<=k;i++){
        int ta,fa,tb,fb;
        cin >> ta >> fa >> tb >> fb;
        int ans = 0;
        if(ta == tb){
            ans = abs(fa - fb);
        }else{
            if(fa < a){
                ans += a - fa; fa = a;
            }else if(fa > b){
                ans += fa - b; fa = b;
            }
            ans += abs(ta - tb);
            ans += abs(fa - fb);
        }
        cout << ans << "\n";
    }


    return 0;
}
