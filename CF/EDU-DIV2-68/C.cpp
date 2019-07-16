#include<bits/stdc++.h>
using namespace std;

int tc;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        string s,t,p;
        cin >> s >> t >> p;
        int n = s.size(), m = t.size(), k = p.size();

        if(n > m){
            puts("NO");
            continue;
        }

        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i != n){
            puts("NO");
        }else{
            vector<int> f(30,0);
            vector<int> f2(30,0);
            for(auto e:s)f[e-'a']++;
            for(auto e:t)f2[e-'a']++;
            for(auto e:p)f[e-'a']++;
            bool ok = true;
            for(int i=0;i<=26;i++){
                ok &= (f[i] >= f2[i]);
            }
            puts(ok ? "YES" : "NO");
        }
    }

    return 0;
}
