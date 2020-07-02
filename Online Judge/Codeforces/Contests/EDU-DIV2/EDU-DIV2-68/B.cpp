#include<bits/stdc++.h>
using namespace std;


int q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while(q--){
        int n,m;
        cin >> n >> m;
        vector<vector<char>> a(n+3,vector<char>(m+3));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        vector<vector<int>> pren(m+3,vector<int>(n+3,0));
        vector<vector<int>> sufn(m+3,vector<int>(n+3,0));
        vector<vector<int>> prem(n+3,vector<int>(m+3,0));
        vector<vector<int>> sufm(n+3,vector<int>(m+3,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pren[i][j] = pren[i][j-1];
                if(a[j][i] == '.')pren[i][j]++;
            }
            for(int j=n;j>=1;j--){
                sufn[i][j] = sufn[i][j+1];
                if(a[j][i] == '.')sufn[i][j]++;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prem[i][j] = prem[i][j-1];
                if(a[i][j] == '.')prem[i][j]++;
            }
            for(int j=m;j>=1;j--){
                sufm[i][j] = sufm[i][j+1];
                if(a[i][j] == '.')sufm[i][j]++;
            }
        }

        int ans = 1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int cur = (a[i][j] == '.' ? 1 : 0);
                cur += sufm[i][j+1];
                cur += prem[i][j-1];
                cur += pren[j][i-1];
                cur += sufn[j][i+1];
                ans = min(ans, cur);
            }
        }
        cout << ans << '\n';

    }

    return 0;
}
