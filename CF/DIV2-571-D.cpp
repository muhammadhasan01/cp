#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
pair<long long, long long> a[N];
bitset<N> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long sum = 0;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        long double x; cin >> x;
        long long fx = floor(x), cx = ceil(x);
        a[i] = {fx,cx}; if(fx != cx)vis[i] = 1;
        sum += cx;
    }
    long long ans;
    for(int i=1;i<=n;i++){
        if(sum > 0 && vis[i]){
            ans = a[i].first;
            sum--;
        }else{
            ans = a[i].second;
        }
        cout << ans << '\n';
    }

    return 0;
}
