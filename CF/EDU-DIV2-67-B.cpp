#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,m;
string s;
int pre[30][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<=26;j++){
            pre[j][i+1] = pre[j][i];
        }
        pre[s[i] - 'a'][i+1]++;
    }
    while(m--){
        string t; cin >> t;
        vector<int> curcnt(27,0);
        for(auto e:t)curcnt[e - 'a']++;
        int ans = 0;
        for(int i=0;i<=26;i++){
            int it = lower_bound(pre[i]+1,pre[i]+1+n,curcnt[i]) - pre[i];
            ans = max(ans, it);
        }
        cout << ans << '\n';
    }

    return 0;
}
