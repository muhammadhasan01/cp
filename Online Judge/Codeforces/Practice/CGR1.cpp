#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod= 1e9+7;
long double PI = acosl(-1);
const ll infl = 1e15;
const int inf = 2e9;
const int nmax = 1e5+10;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

vector<int>g[nmax];
int shomoy;
int intime[nmax], outtime[nmax];

void dfs(int u, int p=0){
	intime[u] = ++shomoy;

    for(auto v : g[u]) if(v!=p)
        dfs(v, u);

    outtime[u] = shomoy;
}

const int bolok = 340;
int dfsarr[nmax];
int cnt[nmax], cntfrq[nmax], mxcnt;
ll cntfrqsum[nmax];


void add(int idx){
    cnt[dfsarr[idx]]++;

    if(cnt[dfsarr[idx]]-1){
        cntfrq[cnt[dfsarr[idx]]-1]--;
        cntfrqsum[ cnt[dfsarr[idx]]-1 ] -= dfsarr[idx];
    }

    cntfrq[cnt[dfsarr[idx]]]++;
    cntfrqsum[ cnt[dfsarr[idx]] ] += dfsarr[idx];

    mxcnt=max(mxcnt, cnt[dfsarr[idx]]);
}

void remov(int idx){
    cnt[dfsarr[idx]]--;

    cntfrq[cnt[dfsarr[idx]]+1]--;
    cntfrqsum[ cnt[dfsarr[idx]]+1 ] -=  dfsarr[idx];

    if(cnt[dfsarr[idx]]){
        cntfrq[cnt[dfsarr[idx]]]++;
        cntfrqsum[ cnt[dfsarr[idx]] ] +=  dfsarr[idx];
    }

    if(cntfrq[mxcnt]==0) mxcnt--;
}

struct queri{
    int L, R, idx;
    bool operator < (const queri &x){
        if(L/bolok == x.L/bolok){
			if(L/bolok % 2) return R > x.R;
			return R < x.R;
        }
        return L < x.L;
    }
};


int col[nmax];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>col[i];

    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    for(int i=1; i<=n; i++)
        dfsarr[ intime[i] ] =  col[i];

    for(int i=1;i<=n;i++) cerr << dfsarr[i] << ' ';
    cerr << '\n';

    int q=n;
    vector<queri>vq(q);
    for(int i=0; i<q; i++){
        vq[i].idx = i;
        vq[i].L = intime[i+1], vq[i].R = outtime[i+1];
    }

    sort(vq.begin(), vq.end());
    vector<ll>ans(q);

    add(1);
    int curL = 1, curR = 1;
    for(queri qq : vq){
        int L = qq.L, R = qq.R;
        while(curR<R) add(++curR);
        while(L<curL) add(--curL);
        while(R<curR) remov(curR--);
        while(curL<L) remov(curL++);
       cout<<curL<<" , "<<curR<<endl;
       cout<<qq.idx+1<<" er ans = "<<cntfrqsum[mxcnt]<<" and mxcnt = "<<mxcnt<<endl;
        ans[qq.idx] = cntfrqsum[mxcnt];
    }
    for(int i=0; i<q; i++)
        cout<<ans[i]<<" ";
}
