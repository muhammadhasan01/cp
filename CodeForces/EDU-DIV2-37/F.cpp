#include<bits/stdc++.h>
using namespace std;

const int N = 3e5;


struct st{
    int l,r;
    long long w;
    bool tag;
};

st t[4*N+5];

int n,m;
long long a[N+5],d[N+5];

void build(int v, int s, int e){
    t[v].l = s, t[v].r = e, t[v].tag = 0;
    if(s == e){
        t[v].w = a[s];
    }else{
        int mid = (s+e)/2;
        build(2*v,s,mid);
        build(2*v+1,mid+1,e);
        t[v].w = t[2*v].w + t[2*v+1].w;
    }
}

void update(int v, int s, int e){
    int l = t[v].l, r = t[v].r;
    //cerr << s << " " << e << '\n';
    if(t[v].tag){
        return;
    }

    if(l == r){
        t[v].w = d[t[v].w];
        if(t[v].w == d[t[v].w]){
            t[v].tag = 1;
        }
        return;
    }

    int mid = (l+r)/2;
    if(e <= mid){
        update(2*v,s,e);
    }else if(s > mid){
        update(2*v+1,s,e);
    }else{
        update(2*v,s,mid);
        update(2*v,mid+1,e);
    }
    t[v].w = t[2*v].w + t[2*v+1].w;
    t[v].tag = (t[2*v].tag && t[2*v+1].tag);
}

long long query(int v, int s, int e){
    int l = t[v].l, r = t[v].r;
    //cerr << s << " - " << e << '\n';
    if(s == e && l == r){
        return t[v].w;
    }
    int mid = (l+r)/2;
    if(e <= mid){
        return query(2*v,s,e);
    }else if(s > mid){
        return query(2*v+1,s,e);
    }else{
        return query(2*v,s,mid) + query(2*v+1,mid+1,e);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            d[j]++;
        }
    }

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    build(1,1,n);

    while(m--){
        int tc,l,r;
        cin >> tc >> l >> r;
        //cerr << tc << " => " << l << " => " << r << '\n';
        if(tc == 1){
            update(1,l,r);
        }else if(tc == 2){
            cout << query(1,l,r) << '\n';
        }
    }


    return 0;
}
