#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    int ans = n;
    for(int j=0;j<=n/2;j++){
        if(s.substr(0,j) == s.substr(j,j)){
            ans = min(ans,j + 1 + n-2*j);
        }
    }
    cout << ans << '\n';

    return 0;
}
