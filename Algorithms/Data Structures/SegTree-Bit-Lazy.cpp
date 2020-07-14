#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+5;
int n,q;
long long bits[N][33], t[4*N][33], lazy[4*N][33];

void build(int v, int s, int e, int k){
    if(s == e){
        t[v][k] = bits[s][k];
    }else{
        int m = (s+e)>>1;
        build(v<<1,s,m,k);
        build(v<<1|1,m+1,e,k);
        t[v][k] = t[v<<1][k] + t[v<<1|1][k];
    }
}

void update(int v, int s, int e, int l, int r, int k){
    if(lazy[v][k]){
        t[v][k] = (e-s+1) - t[v][k];
        if(s != e){
            lazy[v<<1][k] ^= 1;
            lazy[v<<1|1][k] ^= 1;
        }
        lazy[v][k] = 0;
    }

    if(s > r || l > e){
        return;
    }

    if(l <= s && e <= r){
        t[v][k] = (e-s+1) - t[v][k];
        if(s != e){
            lazy[v<<1][k] ^= 1;
            lazy[v<<1|1][k] ^= 1;
        }
        lazy[v][k] = 0;
        return;
    }

    int m = (s+e)>>1;
    update(v<<1,s,m,l,r,k);
    update(v<<1|1,m+1,e,l,r,k);
    t[v][k] = t[v<<1][k] + t[v<<1|1][k];
}

long long query(int v, int s, int e, int l, int r, int k){
    if(lazy[v][k]){
        t[v][k] = (e-s+1) - t[v][k];
        if(s != e){
            lazy[v<<1][k] ^= 1;
            lazy[v<<1|1][k] ^= 1;
        }
        lazy[v][k] = 0;
    }


    if(s > r || e < l){
        return 0;
    }

    if(l <= s && e <= r){
        return t[v][k];
    }

    int m = (s+e)>>1;
    return query(v<<1,s,m,l,r,k) + query(v<<1|1,m+1,e,l,r,k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        for(int j=0;j<=30;j++){
            if(x & (1<<j))bits[i][j]++;
        }
    }

    for(int i=0;i<=30;i++){
        build(1,1,n,i);
    }

    while(q--){
        int qt,l,r;
        cin >> qt >> l >> r;
        if(qt == 2){
            long long ans = 0;
            for(int i=0;i<=30;i++){
                ans += ((long long)1<<i) * query(1,1,n,l,r,i);
            }
            cout << ans << '\n';
        }else if(qt == 1){
            int pos;
            cin >> pos;
            update(1,1,n,l,r,pos);
        }
    }

    return 0;
}
