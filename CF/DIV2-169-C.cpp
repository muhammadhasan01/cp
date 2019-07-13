#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,q;
long long a[N], cnt[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=q;i++){
        int l,r; cin >> l >> r;
        cnt[l]++, cnt[r+1]--;
    }

    for(int i=1;i<=n;i++){
        cnt[i] += cnt[i-1];
    }

    sort(cnt+1,cnt+1+n);
    sort(a+1,a+1+n);

    long long sum = 0;
    for(int i=1;i<=n;i++){
        sum += (a[i] * (long long)(1) * cnt[i]);
    }
    cout << sum << "\n";

    return 0;
}
