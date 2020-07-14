#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define formn(i,n) for(int i=0;i<=(int)n;i++)
#define debug1(i) printf("debug => %ld\n",i);
#define debug2(i,j) printf("debug => %ld - %ld\n",i,j);
#define debug3(i,j,k) printf("debug => %ld - %ld - %ld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 100*1000;
int n,m,x;
vector<int> v[N+3];
bitset<N+3> b;

void dfs(int x){
    b[x] = 1;
    for(int i=0;i<LEN(v[x]);i++){
        if(b[v[x][i]] == 0){
            dfs(v[x][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,m){
        int p,q;
        cin >> p >> q;
        v[p].pb(q);
        v[q].pb(p);
    }
    cin >> x;
    dfs(x);
    int cnt = 0;
    forn(i,n){
        if(b[i] == 0)cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
