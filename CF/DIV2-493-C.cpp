#include<bits/stdc++.h>
using namespace std;

int n;
long long x,y,ans = 1e18;
string s;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y >> s;
    vector<char> cs(n+5);
    int len = 0;
    char last = '#';
    long long cnt = 0;
    for(int i=0;i<n;i++){
        if(last != s[i]){
            cs[++len] = s[i];
            last = s[i];
            if(s[i] == '0')cnt++;
        }
    }

    if(cnt == 0)ans = 0;

    for(long long i=1;i<=cnt;i++){
        long long res = y * i + x * (cnt - i);
        ans = min(ans, res);
    }

    cout << ans << '\n';


    return 0;
}
