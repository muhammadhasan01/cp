#include<bits/stdc++.h>

using namespace std;

long long x, s, a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> x;
    if(abs(s - x) & 1 || x > s){
        puts("0");
        return 0;
    }

    a = (s - x) / 2;
    long long ans = 1;
    for(int i = 0; i <= 60; i++){
        int xb = x >> i & 1;
        int ab = a >> i & 1;
        if(ab && xb){
            ans *= 0;
        }else if(xb){
            ans *= 2;
        }
    }
    if(s == x) ans -= 2;
    cout << ans << '\n';


    return 0;
}
