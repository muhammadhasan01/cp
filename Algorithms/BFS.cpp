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
int n,x;
vector<int> v[N+3];
int dis[N+3];

void bfs(){
    queue<int> q;
    q.push(1);
    dis[1] = 1;
    while(!q.empty()){
        int k = q.front();
        //debug1(k);
        q.pop();
        form(i,LEN(v[k])){
            if(dis[v[k][i]] == 0)
                q.push(v[k][i]), dis[v[k][i]] = 1+dis[k];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,n-1){
        int p,q;
        cin >> p >> q;
        v[p].pb(q);
        v[q].pb(p);
    }
    MEM(dis,0);
    cin >> x;
    bfs();
    int cnt = 0;
    forn(i,n-1){
        if(dis[i] == x)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
