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
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1e4+5;
int n,tc;
int height[N], first[N], parent[N];
ll dist[N];
bitset<N> vis;
vector<int> el, t;

void dfs(vector<pii> g[], int v, int h, ll sum){
    vis[v] = 1;
    height[v] = h;
    first[v] = el.size();
    dist[v] = sum;
    el.pb(v);
    for(auto e:g[v]){
        if(vis[e.ff] == 0){
            parent[e.ff] = v;
            dfs(g,e.ff,h+1,sum+(ll)e.ss);
            el.pb(v);
        }
    }
}

void build(int v, int s, int e){
    if(s == e){
        t[v] = el[s];
    }else{
        int m = (s+e)/2;
        build(2*v,s,m);
        build(2*v+1,m+1,e);
        int l = t[2*v], r = t[2*v+1];
        t[v] = (height[l] < height[r]) ? l : r;
    }
}

ll lca(int v, int s, int e, int l, int r){
    if(s > r || l > e){
        return -1;
    }
    if(l <= s && e <= r){
        return t[v];
    }

    int m = (s+e)/2;
    ll left = lca(2*v,s,m,l,r);
    ll right = lca(2*v+1,m+1,e,l,r);
    if(left == -1)return right;
    if(right == -1)return left;
    return (height[left] < height[right]) ? left : right;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    forn(T,1,tc){
        vis.reset();
        el.clear();
        t.clear();
        MEM(dist,0);
        MEM(height,0);
        MEM(first,0);
        MEM(parent,0);
        parent[1] = 1;
        vector<pii> g[N];
        cin >> n;
        forn(i,1,n-1){
            int u,v,w;
            cin >> u >> v >> w;
            g[u].pb({v,w});
            g[v].pb({u,w});
        }
        dfs(g,1,0,0);
        int els = el.size();
        //for(auto e:el){
            //cout << e << " => " << height[e] << " => " << dist[e] << "\n";
        //}
        t.resize(4*els);
        build(1,0,els-1);
        string s = "";
        while(true){
            cin >> s;
            if(s == "DIST"){
                int x,y;
                cin >> x >> y;
                int l = first[x], r = first[y];
                if(l > r)swap(l,r);
                //cout << l << " " << r << "\n";
                int lc = lca(1,0,els-1,l,r);
                //cout << lc << "\n";
                cout << dist[x]+dist[y]-2*dist[lc] << "\n";
            }else if(s == "KTH"){
                int x,y,k;
                cin >> x >> y >> k;
                int l = first[x], r = first[y];
                if(l > r)swap(l,r);
                //cout << l << " " << r << "\n";
                int lc = lca(1,0,els-1,l,r);
                //cout << lc << "\n";
                int hi = height[x] - height[lc];
                if(hi == k-1){
                    cout << lc << "\n";
                    continue;
                }else if(hi > k-1){
                    int ans = x;
                    forn(i,1,k-1){
                        ans = parent[ans];
                    }
                    cout << ans << "\n";
                }else if(hi < k-1){
                    k = height[y] - height[lc] - (k - hi - 1) + 1 ;
                    int ans = y;
                    forn(i,1,k-1){
                        ans = parent[ans];
                    }
                    cout << ans << "\n";
                }
            }else if(s == "DONE"){
                break;
            }
        }
        cout << "\n";
    }


    return 0;
}
