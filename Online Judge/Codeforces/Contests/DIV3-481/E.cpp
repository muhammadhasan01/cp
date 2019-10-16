#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n;
long long w, a[N], pre[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + (long long)a[i];
    }

    long long l = 0, r = w;
    for(int i=1;i<=n;i++){
        long long cl = -pre[i], cr = w - pre[i];
        l = max(l, cl);
        r = min(r, cr);
    }

    cout << max(r - l + 1, (1LL) * 0) << '\n';

    return 0;
}
