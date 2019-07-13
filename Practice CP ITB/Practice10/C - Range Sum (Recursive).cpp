#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define pf push_front
using namespace std;

const int N = 2*100*1000;
ll tree[4*N+3];
ll a[N+3];
int n;

void build(int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, ll val){
    if(start == end){
        tree[node] = val;
    }else{
        int mid = (start+end)/2;
        if(idx <= mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node+1,mid+1,end,idx,val);
        }
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}

ll query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
        return 0;
    }else if(l <= start && end <= r){
        return tree[node];
    }
    int mid = (start+end)/2;
    ll p = query(2*node,start,mid,l,r);
    ll q = query(2*node+1,mid+1,end,l,r);
    return p+q;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    MEM(a,0);
    for(int i=1;i<=n;i++){
        cin >> a[N-n+i];
    }
    build(1,1,N);
    int q; cin >> q;
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int l,r; cin >> l >> r;
            l = N-n+l, r = N-n+r;
            //cout << l << ',' << r << "\n";
            //cout << a[l] << "\n";
            cout << query(1,1,N,l,r) << "\n";
        }else{
            ll val;
            cin >> val;
            update(1,1,N,N-n,val);
            n++;
        }
    }
    return 0;
}
