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
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,m,p;
char a[1005][1005];
int s[15], ans[15];
bool vis[1005][1005];
queue<pair<pii,int>> q[15];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;

    forn(i,1,p){
        cin >> s[i];
        par[i] = i;
    }

    forn(i,1,n){
        forn(j,1,m){
            cin >> a[i][j];
            if(a[i][j] >= '1' && a[i][j] <= '9'){
                int kk = a[i][j] - '0';
                q[kk].push({{i,j},s[kk]});
                vis[i][j] = 1;
            }
            if(a[i][j] == '#')vis[i][j] = 1;
        }
    }

    int cx[4] = {-1,1,0,0};
    int cy[4] = {0,0,1,-1};

    int t = 1, cnt = 0;
    while(cnt < p){
        //cerr << cnt << " => " << t << " : \n";
        if(q[t].empty()){
            t++; if(t > p)t = 1;
            continue;
        }
        queue<pair<pii,int> > tmp;
        while(!q[t].empty()){
            int x = q[t].front().ff.ff, y = q[t].front().ff.ss;
            int z = q[t].front().ss;
            //cerr << x << "," << y << " => " << z << "\n";
            q[t].pop();
            if(z > 0){
                ans[t]++;
                forn(i,0,3){
                    int dx = x + cx[i];
                    int dy = y + cy[i];
                    if(1 <= dx && dx <= n && 1 <= dy && dy <= m && !vis[dx][dy]){
                        q[t].push({{dx,dy},z-1});
                        vis[dx][dy] = 1;
                    }
                }
            }else{
                tmp.push({{x,y},s[t]});
            }
        }
        q[t] = tmp;
        if(q[t].empty())cnt++;
        t++; if(t > p)t = 1;
    }

    forn(i,1,p)cout << ans[i] << " ";


    return 0;
}
