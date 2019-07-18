#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int tc;
int n;
long long m,k;
long long a[N], pre[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        cin >> m >> n >> k;
        long long temp = m;
        int pos = 1e9;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + k - a[i];
            if(temp > 0)temp += k;
            if(a[i] > temp)pos = min(pos,i-1);
            temp -= a[i];
        }

        if(pos <= n){
            cout << pos << '\n';
            continue;
        }

        if(pre[n] >= 0){
            cout << -1 << '\n';
            continue;
        }

        long long ans = 1e18;
        for(int i=1;i<=n;i++){
            
        }
    }


    return 0;
}
