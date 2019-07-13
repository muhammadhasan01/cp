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

const int N = 100003;
int tc, n, qr;
int vis[N], kids[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n;
        vector<int> g[n+5];
        forn(i,1,n-1){
            int u,v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
            vis[i] = 0, kids[i] = 0;
        }
        vis[n] = 0, kids[n] = 0;
        int par[n+3];
        deque<int> dq;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int k1 = q.front();
            dq.pf(k1);
            vis[k1] = 1;
            q.pop();
            for(auto e:g[k1]){
                if(!vis[e]){
                    q.push(e);
                    par[e] = k1;
                }
            }
        }

        par[1] = 1;
        for(auto x:dq){
            //cout << x << " ";
            if(x != 1){
                if(LEN(g[x]) == 1){
                    kids[par[x]]++;
                }else{
                    kids[par[x]] += 1+kids[x];
                }
                //kids[par[x]] += LEN(g[x]);
            }
        }//cout << "\n";

        forn(i,1,n){
            cout << i << " => " << kids[i] << "\n";
        }

        cin >> qr;
        forn(i,1,qr){
            int x,y;
            cin >> x >> y;
            if(x == y){
                cout << n-1 << "\n";
            }else if(x == 1){
                cout << kids[y] << "\n";
            }else{
                int m1 = x, m2 = y, k = 0;
                while(1){
                    k++;
                    //cout << m1 << " => " << par[m1] << " => " <<  k << "\n";
                    m1 = par[m1];
                    if(m1 == m2){
                        cout << n-(k+kids[x]+1) << "\n";
                        break;
                    }else if(m1 == 1){
                        cout << kids[y] << "\n";
                        break;
                    }
                }

            }
        }
    }


    return 0;
}
