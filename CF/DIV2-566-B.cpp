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

const int N = 505;
int h,w;
char a[N][N];
bool vis[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool check(int x, int y){
    forn(i,0,3){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(a[xx][yy] == '.')return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    forn(i,1,h){
        forn(j,1,w){
            cin >> a[i][j];
        }
    }

    bool ok = false;
    forn(i,2,h-1){
        forn(j,2,w-1){
            if(a[i][j] == '*' && check(i,j)){
                cerr << i << " and " << j << "\n";
                vis[i][j] = 1;
                forn(k,0,3){
                    int p1 = dx[k], p2 = dy[k];
                    int t1 = i, t2 = j;
                    while(1 <= t1 && t1 <= h && 1 <= t2 && t2 <= w && a[t1][t2] == '*'){
                        cerr << i << " => " << t1 << " and " << t2 << "\n";
                        vis[t1][t2] = 1;
                        t1 += p1;
                        t2 += p2;
                    }
                }
                ok = true;
                break;
            }
        }
        if(ok)break;
    }

    bool flag = false;
    forn(i,1,h){
        forn(j,1,w){
            if(a[i][j] == '*' && vis[i][j] != 1){
                //cerr << i << " and " << j << "**" << "\n";
                puts("NO"); ex;
            }
            if(a[i][j] == '*')flag = true;
        }
    }

    puts(flag ? "YES" : "NO");



    return 0;
}
