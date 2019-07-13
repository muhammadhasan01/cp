#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m,k;
long long a[N], cnt[N], cnt2[N];
pair<pair<int,int>,long long> p[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> p[i].first.first >> p[i].first.second >> p[i].second;
    }
    for(int i=1;i<=k;i++){
        int l,r; cin >> l >> r;
        cnt[l]++;
        cnt[r+1]--;
    }
    for(int i=1;i<=m;i++){
        cnt[i] += cnt[i-1];
    }
    for(int i=1;i<=m;i++){
        int l = p[i].first.first;
        int r = p[i].first.second;
        long long d = p[i].second;
        d *= cnt[i];
        cnt2[l] += d;
        cnt2[r+1] -= d;
    }

    for(int i=1;i<=n;i++){
        cnt2[i] += cnt2[i-1];
    }

    for(int i=1;i<=n;i++){
        cout << a[i] + cnt2[i] << " ";
    }

    return 0;
}
