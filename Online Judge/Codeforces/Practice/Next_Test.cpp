#include<bits/stdc++.h>
using namespace std;

const int N = 3e3+5;
bitset<N> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        vis[x] = 1;
    }
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}
