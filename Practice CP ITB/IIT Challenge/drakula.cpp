#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pqg priority_queue<long long, vector<long long>, greater<long long> >
#define pql priority_queue<long long>
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll n, m, u, v, w;
int s = 1;

ll MST(vector<pll> a[]){

    ll mst = 0;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    vector<ll> key(n+2,inf);
    vector<bool> vis(n+2,false);
    key[s] = 0;
    pq.push(mp(0,s));
    while(!pq.empty()){
        ll u = pq.top().ss;
        pq.pop();
        vis[u] = true;
        for(int j=0;j<a[u].size();j++){
            ll v = a[u][j].ff;
            ll w = a[u][j].ss;
            if(vis[v] == false && key[v] > w){
                key[v] = w;
                pq.push(mp(key[v],v));
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=s)mst += key[i];
    }
    return mst;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<pll> a[n+2];
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            cout << i << "," << a[i][j].ff << " => " << a[i][j].ss << "\n";
        }
    }*/
    cout << MST(a) << "\n";

    return 0;
}
