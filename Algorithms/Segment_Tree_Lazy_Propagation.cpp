#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.hackerearth.com/problem/algorithm/range-update-range-max-queries/
// https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

const int NMAX = 100*1000;
ll t[4*NMAX+3];
ll lazy[4*NMAX+3];
ll a[NMAX+3];
int n,q;

void build(int v, int s, int e){
    if(s==e){
        t[v] = a[s];
    }else{
        int m = (s+e)/2;
        build(2*v,s,m);
        build(2*v+1,m+1,e);
        t[v] = min(t[2*v],t[2*v+1]);
    }
}

void updateRange(int v, int s, int e, int l, int r, ll val){
    if(lazy[v] != 0){
        t[v] += lazy[v];
        if(s != e){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }

    if(s > e || s > r || l > e){
        return;
    }

    if(l<=s && e<=r){
        t[v] += val;
        if(s != e){
            lazy[2*v] += val;
            lazy[2*v+1] += val;
        }
        return;
    }

    int m = (s+e)/2;
    updateRange(2*v,s,m,l,r,val);
    updateRange(2*v+1,m+1,e,l,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
}

ll queryRange(int v, int s, int e, int l, int r){
    if(s > e || s > r || l > e){
        return inf;
    }
    if(lazy[v]!=0){
        t[v] += lazy[v];
        if(s!=e){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(l <= s && e <= r){
        return t[v];
    }

    int m = (s+e)/2;
    ll p1 = queryRange(2*v,s,m,l,r);
    ll p2 = queryRange(2*v+1,m+1,e,l,r);
    return min(p1,p2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    forn(i,n)cin>>a[i];
    MEM(lazy,0);
    build(1,1,n);
    while(q--){
        char k;
        cin >> k;
        if(k == 'q'){
            int l,r; cin >> l >> r;
            cout << queryRange(1,1,n,l,r) << "\n";
        }else if(k == 'u'){
            int l,r; ll val;
            cin >> l >> r >> val;
            updateRange(1,1,n,l,r,val);
        }
    }
    return 0;
}
