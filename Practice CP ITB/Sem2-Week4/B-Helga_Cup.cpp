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
#define pii pair<int,int>
using namespace std;

const int N = 1e5+5;
int x, n, k , m;
ll dp[N][3][15];
ll a[3][15], b[3][15];
vector<int> g[N];
ll ans = 0;

void dfs(int v, int p){
    bool flag = false;
    ll temp;
    for(auto e:g[v]){
        if(e == p)continue;
        flag = true;
        dfs(e,v);
    }

    if(!flag){
        dp[v][0][0] = k-1;
        dp[v][1][1] = 1;
        dp[v][2][0] = m-k;
        return;
    }

    forn(i,0,2){
        forn(j,0,x){
            a[i][j] = 0;
            b[i][j] = 0;
        }
    }

    forn(i,0,2)a[i][0] = 1;

    for(auto e:g[v]){

        if(e == p)continue;

        forn(j,0,2){
            forn(l,0,x){
                forn(r,0,x){

                    if(l+r>x)continue;

                    if(j == 0){
                        temp = (dp[e][0][r] + dp[e][1][r] + dp[e][2][r])%MOD;
                    }else if(j == 1){
                        temp = (dp[e][0][r])%MOD;
                    }else if(j == 2){
                        temp = (dp[e][0][r] + dp[e][2][r])%MOD;
                    }

                    b[j][l+r] += (a[j][l] * temp)%MOD;

                }
            }
        }

        forn(j,0,2){
            forn(l,0,x){
                a[j][l] = b[j][l];
                b[j][l] = 0;
            }
        }

    }

    forn(l,0,x){
        dp[v][0][l] = (a[0][l] * (k-1))%MOD;
        if(l >= 1){
            dp[v][1][l] = a[1][l-1];
        }
        dp[v][2][l] = (a[2][l] * (m-k))%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n-1){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> k >> x;
    dfs(1,0);
    forn(i,0,2){
        forn(j,0,x){
            ans += dp[1][i][j]%MOD;
        }
    }

    cout << (ans%MOD+MOD)%MOD << "\n";


    return 0;
}
