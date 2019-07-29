#include<bits/stdc++.h>
using namespace std;

int n,k;
int c[300], p[300];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<=256;i++){
        c[i] = -1;
        p[i] = -1;
    }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        if(c[x] == -1){
            int res = 1e9;
            int cnt = 0, j = x, pos = j;
            bool ok = true;
            while(j >= 0 && cnt < k){
                res = min(res,j);
                pos = j;
                j--;
                cnt++;
                if(j >= 0 && c[j] != -1 && p[c[j]] != -1){
                    if(p[c[j]] + cnt <= k){
                        p[c[j]] += cnt;
                        res = c[j];
                        ok = false;
                    }
                    break;
                }
            }
            if(ok)p[res] = cnt;
            cnt = 0, j = x;
            while(j >= pos){
                c[j] = res;
                j--;
            }
        }
        cout << c[x] << (i == n ? '\n': ' ');
    }


    return 0;
}
