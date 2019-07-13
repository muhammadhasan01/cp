#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n;
int par[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++)cin >> par[i];

    for(int i=1;i<=n;i++){
        vector<bool> vis(n+5,false);
        for(int p=i;;p=par[p]){
            if(vis[p]){
                cout << p << " ";
                break;
            }
            vis[p] = 1;
        }
    }




    return 0;
}
