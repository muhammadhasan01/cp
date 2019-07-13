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

const int N = 1003;
const int L = log2(1003);
int n,q;
int tc, up[N][L], tin[N], tout[N], timer = 0, l;


void dfs(int v, int p, vector<int> g[]){
    up[v][0] = p;
    tin[v] = ++timer;
    forn(i,1,l)up[v][i] = up[up[v][i-1]][i-1];
    for(auto e:g[v]){
        if(e != p){
            dfs(e,v,g);
        }
    }
    tout[v] = ++timer;

}

bool is_anc(int x, int y){
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int LCA(int x, int y){
    if(is_anc(x,y)) return x;
    if(is_anc(y,x)) return y;
    nrof(i,l,0){
        if(!is_anc(up[x][i],y)){
            x = up[x][i];
        }
    }
    return up[x][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    forn(i,1,tc){
        cin >> n;
        vector<int> g[n+5];
        MEM(up,0);
        MEM(tin,0);
        MEM(tout,0);
        timer = 0;

        l = log2(n);
        forn(j,1,n){
            int x;
            cin >> x;
            forn(k,1,x){
                int y;
                cin >> y;
                g[j].pb(y);
                g[y].pb(j);
            }
        }

        dfs(1,1,g);

        cout << "Case " << i << ":\n";
        cin >> q;
        while(q--){
            int x,y;
            cin >> x >> y;
            cout << LCA(x,y) << "\n";
        }
    }



    return 0;
}
