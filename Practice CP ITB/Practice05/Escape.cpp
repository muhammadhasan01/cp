#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<ll,ll>
using namespace std;

const int N = 1000;
int R,C;
string a[N+2];
int dis[N+2][N+2];

void bfs(int i, int j){
    dis[i][j] = 0;
    deque<pair<int,int> > dq;
    dq.push_front(mp(i,j));
    while(!dq.empty()){
        int p = dq.front().first, q  = dq.front().second;
        dq.pop_front();
        int m[4] = {1,0,-1,0}, n[4] = {0,1,0,-1};
        for(int k = 0; k < 4; k++){
            int I = p+m[k];
            int J = q+n[k];
            if(0 <= I && I < R && 0 <= J && J < C){
                if(a[I][J] == a[p][q] && dis[I][J] > dis[p][q]){
                    dis[I][J] = dis[p][q];
                    dq.push_front(mp(I,J));
                }else if(a[I][J] != a[p][q] && dis[I][J] > dis[p][q]+1){
                    dis[I][J] = dis[p][q]+1;
                    dq.push_back(mp(I,J));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int i=0;i<R;i++){
        cin >> a[i];
    }
    for(int i=0;i<R+2;i++){
        for(int j=0;j<C+2;j++){
            dis[i][j] = inf;
        }
    }
    bfs(0,0);
    cout << dis[R-1][C-1]<< "\n";
    return 0;
}
