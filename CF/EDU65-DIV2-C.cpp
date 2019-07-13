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

const int N = 5 * 100 * 1000 + 5;
int n,m;
int par[N], sz[N];

int find(int x){
    if(par[x] == x)return x;
    return par[x] = find(par[x]);
}

void make(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x != y){
        if(sz[y] > sz[x])swap(x,y);
        sz[x] += sz[y];
        par[y] = x;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    forn(i,1,n){
        par[i] = i;
        sz[i] = 1;
    }

    forn(i,1,m){
        int k;
        cin >> k;
        int f;
        forn(j,1,k){
            int m;
            cin >> m;
            if(j == 1){
                f = m;
            }else{
                make(f,m);
            }
        }
    }

    forn(i,1,n){
        int k = find(i);
        cout << sz[k] << " ";
    }


    return 0;
}
