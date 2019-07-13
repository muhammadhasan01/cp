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

const int N = 1e5+3;
const int L = log2(N)+5;
int n, q, l, timer = 0;
vector<int> g[N];
int tin[N], tout[N], height[N], sizes[N], parent[N];
int up[N][L];
bitset<N> vis;
queue<int> qiu;

void dfs(int v, int p, int h){
    vis[v] = 1;
    tin[v] = ++timer;
    height[v] = h;
    up[v][0] = p;
    sizes[v]++;
    forn(i,1,l){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto e:g[v]){
        if(vis[e] == 0){
            parent[e] = v;
            dfs(e,v,h+1);
            sizes[v] += sizes[e];
        }
    }
    tout[v] = ++timer;
    //qiu.push(v);
}

bool is_ans(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){
    if(is_ans(u,v)){
        return u;
    }else if(is_ans(v,u)){
        return v;
    }else{
        for(int i=l;i>=0;i--){
            if(!is_ans(up[u][i],v)){
                u = up[u][i];
            }
        }
        return up[u][0];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n-1){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    l = log2(n);
    dfs(1,1,0);

    /*while(!qiu.empty()){
        int v = qiu.front();
        sizes[v]++;
        sizes[parent[v]] += sizes[v];
        qiu.pop();
    }*/

    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        if(x == y){
            cout << n << "\n";
        }else{
            int anc = lca(x,y);
            int dist = height[x] + height[y] - 2*height[anc];
            //cerr << anc << " => " << dist << "\n";
            if(dist&1){
                cout << 0 << "\n"; continue;
            }
            int target2 = dist/2-1;

            int cnt2 = 0, u = (height[x] > height[y]) ? x : y;
            int v;

            while(target2 != 0){
                if(target2&1){
                    u = up[u][cnt2];
                }
                target2/=2;
                cnt2++;
            }

            v = parent[u];
            //cerr << v << " dan " << u << "\n";

            int ans = 0;
            ans += sizes[v] - sizes[u];
            //cerr << sizes[u] << " " << ans << "\n";
            if(v == anc){
                u = (height[x] <= height[y]) ? x : y;

                target2 = dist/2-1;
                cnt2 = 0;

                while(target2 != 0){
                    if(target2&1){
                        u = up[u][cnt2];
                    }
                    target2/=2;
                    cnt2++;
                }

                ans += (n-sizes[anc]-sizes[u]);
            }

            cout << ans << '\n';
        }

    }



    return 0;
}
