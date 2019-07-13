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
const int L = log2(N);
int n,q,l;
int height[N], tin[N], tout[N];
int up[N][L+3], timer = 0;
vector<int> g[N], gh[N];

void dfs(int v, int p, int h){
    height[v] = h;
    up[v][0] = p;
    tin[v] = ++timer;
    gh[h].pb(tin[v]);
    for(int i=1;i<=L;i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for(auto e:g[v]){
        if(e != p){
            dfs(e,v,h+1);
        }
    }
    tout[v] = ++timer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> nol;
    forn(i,1,n){
        int x;
        cin >> x;
        if(x == 0){
            nol.pb(i);
        }else{
            g[i].pb(x);
            g[x].pb(i);
        }
    }
    //cerr << "HEBATTT\n";

    forn(i,0,LEN(nol)-1){
        dfs(nol[i],nol[i],0);
    }

    cin >> q;
    while(q--){
        int v,p;
        cin >> v >> p;
        if(height[v] < p){
            cout << "0 ";
        }else{
            int c = 0, x = v;
            while(p != 0){
                if(p&1){
                    x = up[x][c];
                }
                p/=2;
                c++;
            }
            int it2 = upper_bound(all(gh[height[v]]), tout[x]) - gh[height[v]].begin();
            int it1 = lower_bound(all(gh[height[v]]), tin[x]) - gh[height[v]].begin();
            cout << max(0,it2-it1-1) << " ";
        }
    }


    return 0;
}
