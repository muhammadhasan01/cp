#include<bits/stdc++.h>
using namespace std;

int q;
long long x[3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--){
        cin >> x[0] >> x[1] >> x[2];
        sort(x,x+3);
        if(x[1] - x[0] > x[2]){
            cout << x[0] + x[2] << '\n';
        }else{
            cout << x[1] + (x[2] - (x[1] - x[0]))/2 << '\n';
        }
    }

    return 0;
}
