#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int tc,n;
pair<int,int> p[N];
int ans[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> p[i].first >> p[i].second;
        }
        int tim = 1;
        for(int i=1;i<=n;i++){
            tim = max(tim, p[i].first);
            if(tim > p[i].second){
                ans[i] = 0;
            }else{
                ans[i] = tim;
                tim++;
            }
        }
        for(int i=1;i<=n;i++){
            cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
