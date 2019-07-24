#include<bits/stdc++.h>
using namespace std;

int q;
int n,k;
string s;
string t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<=2000 + 10;i++){
        if(i%3 == 1){
            t += 'R';
        }else if(i%3 == 2){
            t += 'G';
        }else{
            t += 'B';
        }
    }

    cin >> q;
    while(q--){
        cin >> n >> k >> s;
        string a = t.substr(0,k), b = t.substr(1,k), c = t.substr(2,k);
        deque<char> y;
        int cnt = 0, ans = 1e9;
        for(int i=0;i<n;i++){
            y.push_back(s[i]);
            cnt++;
            if(cnt == k){
                int r1 = 0, r2 = 0, r3 = 0;
                for(int j=0;j<k;j++){
                    if(y[j] != a[j])r1++;
                    if(y[j] != b[j])r2++;
                    if(y[j] != c[j])r3++;
                }
                y.pop_front();
                ans = min(ans, min(r1,min(r2,r3)));
                cnt--;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
