#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int tc;
int n, a[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a+1,a+1+n);
        int ans = min(a[n-1] - 1, n-2);
        cout << ans << '\n';
    }

    return 0;
}
