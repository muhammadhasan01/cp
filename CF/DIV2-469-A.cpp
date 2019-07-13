#include<bits/stdc++.h>
using namespace std;

int l,r,a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> r >> a;
    if(l > r)swap(l,r);
    while(l < r && a > 0){
        l++;
        a--;
    }
    cout << 2 * (min(l,r) + a/2) << '\n';


    return 0;
}
