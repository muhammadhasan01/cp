#include<bits/stdc++.h>
using namespace std;

int tc;
int n,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n >> k;
        vector<vector<int>> ans(k+1,vector<int>(n));
        vector<int> v(n);
        for(int i=0;i<n;i++)cin >> v[i];
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                int pos = j + 2 * i - k;
                pos = (pos%n + n)%n;
                ans[i][j] = v[pos];
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            cout << ans[0][i] << (i == n-1 ? '\n' : ' ');
        }
    }

    return 0;
}
