#include<bits/stdc++.h>
using namespace std;

long long x[4],d;
long long ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x[1] >> x[2] >> x[3] >> d;
    sort(x+1,x+1+3);
    if(x[2] - x[1] < d){
        ans += x[1] - (x[2] - d);
        x[1] = x[2] - d;
    }
    if(x[3] - x[2] < d){
        ans += x[2] + d - x[3];
        x[3] = x[2] + d;
    }

    cout << ans << '\n';



    return 0;
}
