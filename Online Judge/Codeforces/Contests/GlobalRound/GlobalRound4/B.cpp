#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
string s;
long long pre[N], suf[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();
    s = '#' + s + '#';
    int k = 0;
    for(int i=1;i<=n+1;i++){
        pre[i] = pre[i-1];
        if(s[i] == 'v'){
            k++;
        }else{
            pre[i] += max(0,k-1);
            k = 0;
        }
    }

    for(int i=n;i>=0;i--){
        suf[i] = suf[i+1];
        if(s[i] == 'v'){
            k++;
        }else{
            suf[i] += max(0,k-1);
            k = 0;
        }
    }

    long long ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == 'o'){
            ans += pre[i] * suf[i];
        }
    }

    cout << ans << '\n';


    return 0;
}
