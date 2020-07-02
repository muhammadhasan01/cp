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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,pair<int,int>>
using namespace std;

const int N = 2e5+5;
int n, a[N];
pii t[4*N];
vector<pii> v;


void build(int vx, int s, int e){
    if(s == e){
        t[vx] = v[s];
    }else{
        int m = (s+e)/2;
        build(2*vx,s,m);
        build(2*vx+1,m+1,e);
        if(t[2*vx].ss.ss >= t[2*vx+1].ss.ss){
            t[vx] = t[2*vx];
        }else{
            t[vx] = t[2*vx+1];
        }
    }
}

void update(int vx, int s, int e, int p, int val){
    if(s == e){
        if(p == s){
            v[s].ss.ss = val;
            t[vx] = v[s];
        }
    }else{
        int m = (s+e)/2;
        if(m >= p){
            update(2*vx,s,m,p,val);
        }else{
            update(2*vx+1,m+1,e,p,val);
        }
        if(t[2*vx].ss.ss >= t[2*vx+1].ss.ss){
            t[vx] = t[2*vx];
        }else{
            t[vx] = t[2*vx+1];
        }
    }
}

pii get(int vx, int s, int e, int l, int r){
    if(l > s || r < e){
        return {-1,{-1,-1}};
    }
    if(l <= s && e <= r){
        return t[vx];
    }
    int m = (s+e)/2;
    pii a = get(2*vx,s,m,l,r);
    pii b = get(2*vx+1,m+1,e,l,r);
    if(a.ss.ss >= b.ss.ss){
        return a;
    }else{
        return b;
    }
}

int find_set(int x[], int v){
    if(x[v] == v)return v;
    return x[v] = find_set(x,x[v]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin >> a[i];
    int maks = -1, pos = 0, cnt = 0;
    int last = a[1];
    forn(i,1,n){
        if(last == a[i]){
            cnt++;
        }else{
            int k = sz(v);
            v.pb({k,{last,cnt}});
            last = a[i];
            cnt = 1;
        }
    }

    int k = sz(v);
    v.pb({k,{last,cnt}});
    /*for(auto e:v){
        cout << e.ff << " => " << e.ss.ff << " " << e.ss.ss << "\n";
    }
    cout << "\n";*/
    k = sz(v);
    int pre[k+5], erp[k+5];
    for(int i=0;i<k+5;i++){
        pre[i] = i;
        erp[i] = i;
    }
    build(1,0,k-1);
    pii res = {-1,{-1,-1}};
    int ans = 0;
    while(res.ss.ss != 0){
        ans++;
        res = get(1,0,k-1,0,k-1);
        //cout << res.ff << " => " << res.ss.ff << " " << res.ss.ss << "\n";
        int pos = res.ff;
        update(1,0,k-1,pos,0);
        if(pos > 0)pre[pos] = find_set(pre,pre[pos-1]);
        if(pos < k-1)erp[pos] = find_set(erp,erp[pos+1]);
        pii x = {-1,{-1,-1}}, y = {-1,{-2,-1}};
        x = v[pre[pos]], y = v[erp[pos]];

        if(x.ss.ss == 0 || y.ss.ss == 0)continue;

        if(x.ss.ff == y.ss.ff){
            int temp = x.ss.ss+y.ss.ss;
            update(1,0,k-1,x.ff,temp);
            update(1,0,k-1,y.ff,0);
            if(y.ff > 0)pre[y.ff] = find_set(pre,pre[y.ff-1]);
            if(y.ff < k-1)erp[y.ff] = find_set(erp,erp[y.ff+1]);
        }
    }

    cout << ans-1 << "\n";

    return 0;
}
