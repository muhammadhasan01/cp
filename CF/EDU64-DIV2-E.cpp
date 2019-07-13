#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 2e5+5;
int n;
int a[N], t[4*N], par[N];

void build(int v, int s, int e){
    if(s == e){
        t[v] = a[s];
    }else{
        int m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1,m+1,e);
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

int query(int v, int s, int e, int l, int r){
    if(s > r || e < l){
        return -1;
    }
    if(l <= s && e <= r)return t[v];
    int m = (s+e)/2;
    return max(query(2*v,s,m,l,r), query(2*v+1,m+1,e,l,r));
}

int ans(int le, int ri){
    if(ri - le <= 1)return 0;
    int val = query(1,1,n,le,ri);
    int pos = par[val];
    int ret = 0;

    if((ri - pos) < (pos - le)){ // optimized
        forn(i,pos+1,ri){
            int temp = val - a[i];
            if(par[temp] >= le && par[temp] < pos)ret++;
        }
    }else{
        forn(i,le,pos){
            int temp = val - a[i];
            if(par[temp] <= ri && par[temp] > pos)ret++;
        }
    }

    ret += ans(le,pos - 1) + ans(pos+1,ri);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        cin >> a[i];
        par[a[i]] = i;
    }
    build(1,1,n);
    cout << ans(1,n) << "\n";


    return 0;
}
