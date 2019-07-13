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
#define csort(x,n) sort(x.begin()+1,x.begin()+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 100*1000;
vector<int> tree(2*NMAX+3);
vector<int> a(NMAX+3);
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

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        a[idx] = val;
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

int query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
        return 0;
    }
    if(l<=start && end <= r){
        return tree[node];
    }

    int mid = (start+end)/2;
    int p1 = query(2*node,start,mid,l,r);
    int p2 = query(2*node+1,mid+1,end,l,r);
    return p1+p2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    forn(n)cin>>a[i];
    build(1,1,n);
    update(1,1,n,1,1);
    cout << query(1,1,n,1,n) << "\n";

    return 0;
}
