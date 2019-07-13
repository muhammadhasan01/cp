#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    vector<int> pre(n+3,0), suf(n+3,0);
    int ans = 0;
    for(int i=1,j=0;i<=n;i++){
        pre[i] = pre[i-1];
        if(pre[i] == -1)continue;
        if(s[i-1] == '(')j++;
        else j--;
        pre[i] = j;
    }
    for(int i=n,j=0;i>=1;i--){
        suf[i] = suf[i+1];
        if(suf[i] == 1)continue;
        if(s[i-1] == '(')j++;
        else j--;
        suf[i] = j;
    }
    for(int i=1;i<=n;i++){
        int temp = 0;
        if(s[i-1] == ')')temp++;
        else temp--;
        if(pre[i-1] != -1 && suf[i+1] != 1 && pre[i-1] + suf[i+1] + temp == 0){
            ans++;
        }
    }
    cout << ans << "\n";


    return 0;
}
