#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n,m;
int c[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> f(n+3,0);
    int ans = 0, mm = 1;
    for(int i=1;i<=m;i++)cin >> c[i];
    for(int i=1;i<=m;i++){
        f[c[i]]++;
        bool flag = true;
        for(int j=1;j<=n;j++){
            if(f[j] < mm){
                flag = false;
                break;
            }
        }
        if(flag){
            ans++, mm++;
        }
    }
    cout << ans << '\n';

    return 0;
}
