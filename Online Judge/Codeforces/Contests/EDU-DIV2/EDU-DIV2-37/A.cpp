#include<bits/stdc++.h>
using namespace std;

const int N = 205;
int tc;
int n,k,a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n >> k;
        vector<bool> vis(n+3,false);

        for(int i=1;i<=k;i++){
            cin >> a[i];
            vis[a[i]] = 1;
        }

        int time = 1;
        while(true){
            bool ok = true;
            for(int i=1;i<=n;i++){
                ok &= vis[i];
            }
            if(ok){
                cout << time << '\n';
                break;
            }
            vector<bool> temp(n+3,false);
            for(int i=1;i<=n;i++){
                if(vis[i]){
                    temp[i-1] = 1;
                    temp[i] = 1;
                    temp[i+1] = 1;
                }
            }
            vis = temp;
            time++;
        }
    }

    return 0;
}
