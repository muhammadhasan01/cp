#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin >> v[i];
        vector<bool> f(n,true);
        for(int i=0;i<k;i++)f[i] = false;
        int ans = 0;
        do{
            int cur = 0;
            for(int i=0;i<n;i++)if(!f[i])cur ^= v[i];
            ans = max(ans,cur);
        }while(next_permutation(f.begin(),f.end()));
        cout << ans << '\n';
    }


    return 0;
}
