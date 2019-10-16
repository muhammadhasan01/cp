#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    int ans = 0, len = 0;
    s += '#';
    for(int i=0;i<=n;i++){
        if(s[i] == 'x'){
            len++;
        }else{
            ans += max(0, len - 2);
            len = 0;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
