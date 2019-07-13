#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define ff first
#define ss second
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 3*100*1000;
const int J = 2;
ll n;
ll a[N+2][J+2];
int vis[N+2][J+2];

ll ans(ll i, ll j, ll c, int vis[N+2][J+2]){
    //cout << i << "," << j << " => " << a[i][j] << "*" << c << "\n";
    ll jawab = 0;
    if(j==2 && (i==n || vis[i+1][j]!=-1) && (i==1 || vis[i-1][j]!=-1) && vis[i][j-1] !=-1 ){
        //cout << "FIN1\n";
        return a[i][j]*c;
    }
    if(j==1 && (i==n || vis[i+1][j]!=-1) && vis[i-1][j]!=-1 && vis[i][j+1]!=-1 ){
        //cout << "FIN2\n";
        return a[i][j]*c;
    }
    if(i+1<=n && vis[i+1][j] == -1){
        //cout << "1\n";
        vis[i+1][j] = 1;
        jawab = a[i][j]*c+ans(i+1,j,c+1,vis);
        //cout << jawab << "\n";
        vis[i+1][j] = -1;
    }
    if(j == 1 && vis[i][j+1] == -1){
        //cout << "2\n";
        vis[i][j+1] = 1;
        jawab = max(jawab,a[i][j]*c+ans(i,j+1,c+1,vis));
        vis[i][j+1] = -1;
    }
    if(j == 2 && vis[i][j-1] == -1){
        //cout << "3\n";
        vis[i][j-1] = 1;
        jawab = max(jawab,a[i][j]*c+ans(i,j-1,c+1,vis));
        vis[i][j-1] = -1;
    }
    if(i > 1 && vis[i-1][j] == -1){
        //cout << "4\n";
        vis[i-1][j] = 1;
        jawab = max(jawab,a[i][j]*c+ans(i-1,j,c+1,vis));
        vis[i-1][j] = -1;
    }
    return jawab;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int j=1;j<=2;j++){
        for(int i=1;i<=n;i++){
            cin >> a[i][j];
        }
    }
    memset(vis,-1,sizeof(vis));
    vis[1][1] = 1;
    cout << ans(1,1,0,vis) << "\n";
}
