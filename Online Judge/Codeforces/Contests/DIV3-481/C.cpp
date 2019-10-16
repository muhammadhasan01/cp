#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,m;
long long a[N],b[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i=1;i<=m;i++){
        long long x; cin >> x;
        int pos = lower_bound(a + 1, a + 1 + n, x) - a;
        cout << pos << " " << x - a[pos - 1] << '\n';
    }


    return 0;
}
