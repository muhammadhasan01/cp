#include<bits/stdc++.h>
using namespace std;

int q;
int n,k;
string s;
// rgb , gbr, brg

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> q;
    while(q--){
        cin >> n >> k >> s;
        int cnt = 0;
        int ans = 1e9;
        int r1 = 0, r2 = 0, r3 = 0;
        s = "#" + s;
        for(int i=1;i<=n;i++){
            r1++, r2++, r3++;
            if(s[i] == 'R'){
                if(i%3 == 1)r1--;
                else if(i%3 == 2)r3--;
                else if(i%3 == 0)r2--;
            }else if(s[i] == 'G'){
                if(i%3==1)r2--;
                else if(i%3==2)r1--;
                else if(i%3 == 0)r3--;
            }else if(s[i] == 'B'){
                if(i%3==1)r3--;
                else if(i%3==2)r2--;
                else if(i%3 == 0)r1--;
            }

            cnt++;
            if(cnt == k){
                ans = min(ans, min(r1,min(r2,r3)));
                r1--, r2--, r3--;
                int j = i-k+1;
                if(s[j] == 'R'){
                    if(j%3 == 1)r1++;
                    else if(j%3 == 2)r3++;
                    else if(j%3 == 0)r2++;
                }else if(s[j] == 'G'){
                    if(j%3==1)r2++;
                    else if(j%3==2)r1++;
                    else if(j%3 == 0)r3++;
                }else if(s[j] == 'B'){
                    if(j%3==1)r3++;
                    else if(j%3==2)r2++;
                    else if(j%3 == 0)r1++;
                }
                cnt--;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
