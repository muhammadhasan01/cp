#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(ll i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<ll,ll>
using namespace std;

const ll K = 1e5;
ll N,M,X,t1,t2;
vector<ll> a[K+2];
ll dis[K+2];

void dfs(ll x){
    bool vis[N+2]; MEM(vis,false);
    queue<pair<ll,ll> > q;
    q.push(make_pair(x,0));
    dis[x] = 0;
    vis[x] = true;
    while(!q.empty()){
        ll x = q.front().first, depth = q.front().second;
        q.pop();
        for(ll j=0;j<a[x].size();j++){
            if(vis[a[x][j]]==false){
                vis[a[x][j]] = true;
                q.push(make_pair(a[x][j],depth+1));
                dis[a[x][j]] = depth+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    for(ll i=0;i<M;i++){
        cin >> t1 >> t2;
        a[t2].push_back(t1);
    }
    MEM(dis,-1);
    dfs(X);
    for(ll i=1;i<=N;i++){
        cout << dis[i] << "\n";
    }
    return 0;
}
