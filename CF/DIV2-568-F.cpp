#include<bits/stdc++.h>
using namespace std;

const int M = (1<<9);
int n,m;
int dp[M+5];
vector<pair<int,int>> p[M+5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        int res = 0;
        for(int j=1;j<=x;j++){
            int y; cin >> y;
            y--;
            res |= (1<<y);
        }
        dp[res]++;
    }
    for(int i=1;i<=m;i++){
        int c; cin >> c;
        int x; cin >> x;
        int res = 0;
        for(int j=1;j<=x;j++){
            int y; cin >> y;
            y--;
            res |= (1<<y);
        }
        p[res].push_back({c,i});
        sort(p[res].begin(),p[res].end());
        while((int)p[res].size() > 2) p[res].pop_back();
    }
    pair<int,int> ans = {0,0};
    int mcount = 0, mcost = 2e9+10;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            int cost = 0;
            pair<int,int> rans;
            if(i == j){
                if((int)p[i].size() < 2)continue;
                cost = p[i][0].first + p[j][1].first;
                rans = {p[i][0].second,p[j][1].second};
            }else{
                if((int)p[i].size() == 0 || (int)p[j].size() == 0)continue;
                cost = p[i][0].first + p[j][0].first;
                rans = {p[i][0].second,p[j][0].second};
            }

            int mask = (i | j);
            int rcnt = 0;
            for(int k=0;k<M;k++){
                if((mask & k) == k){
                    rcnt += dp[k];
                }
            }
            if(rcnt > mcount || (rcnt == mcount && cost < mcost)){
                ans = rans;
                mcount = rcnt;
                mcost = cost;
            }
        }
    }
    cout << ans.first << " " << ans.second << '\n';

    return 0;
}
