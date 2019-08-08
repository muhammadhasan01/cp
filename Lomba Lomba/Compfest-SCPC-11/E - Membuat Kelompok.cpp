#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,k;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    n *= 2;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    bool ok = true;
    for(int i=1;i<n;i++){
        ok &= (a[i+1] - a[i] <= k);
        if(!ok)break;
    }
    cout << (ok ? "Ya" : "Tidak") << '\n';

    return 0;
}
