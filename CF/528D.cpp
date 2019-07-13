#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define rofn(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 100003;
int n;
ld s, cnt = 0;
vector<int> v[N];
bitset<N> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    cin >> n >> s;
    forn(i,1,n-1){
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int k  = q.front();
        q.pop();
        vis[k] = 1;
        if(LEN(v[k]) == 1)cnt++;
        forn(i,0,LEN(v[k])-1){
            int p = v[k][i];
            if(vis[p] == 0){
                q.push(p);
            }
        }
    }

    cout << 2*s/cnt << "\n";

    return 0;
}
