#include<bits/stdc++.h>
using namespace std;

int tc;
string s1,s2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        cin >> s1 >> s2;
        int k1 = s1.size(), k2 = s2.size();
        s1 += '$', s2 += '$';
        vector<pair<int,char>> v1(k1+5,{0,'#'}), v2(k2+5,{0,'#'});
        int len1 = 0, len2 = 0;
        int cnt = 1;
        for(int i=0;i<=k1;i++){
            if(s1[i] == s1[i+1]){
                cnt++;
            }else{
                v1[++len1] = {cnt,s1[i]};
                cnt = 1;
            }
        }
        for(int i=0;i<=k2;i++){
            if(s2[i] == s2[i+1]){
                cnt++;
            }else{
                v2[++len2] = {cnt,s2[i]};
                cnt = 1;
            }
        }
        if(len1 != len2){
            puts("NO");
        }else{
            bool flag = true;
            for(int i=1;i<=len1;i++){
                if(v1[i].second != v2[i].second){
                    flag = false;
                    break;
                }else if(v1[i].first > v2[i].first){
                    flag = false;
                    break;
                }
            }
            puts(flag ? "YES" : "NO");
        }
    }



    return 0;
}
