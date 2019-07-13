#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
const int M = 2e5+10;
int n, a[N];
int k[M];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int maxi = -1;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int res = a[i] + a[j];
            maxi = max(maxi, res);
            k[res]++;
        }
    }

    int ans = -1;
    for(int i=1;i<=maxi;i++){
        ans = max(ans, k[i]);
    }
    cout << ans << "\n";


    return 0;
}
