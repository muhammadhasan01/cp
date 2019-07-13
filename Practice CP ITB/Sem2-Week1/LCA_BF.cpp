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

int n,q;
int tc, parent[1003], vis[1003];

int LCA(int x, int y){

    MEM(vis,0);

    vis[x] = 1;

    while(parent[x] != x){
        vis[x] = 1;
        x = parent[x];
    }

    vis[x] = 1;

    while(vis[y] != 1)y = parent[y];

    return y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    forn(i,1,tc){
        cin >> n;

        forn(j,1,n)parent[j] = j;

        forn(j,1,n){
            int x;
            cin >> x;
            forn(k,1,x){
                int y;
                cin >> y;
                parent[y] = j;
            }
        }

        cout << "Case " << i << ":\n";
        cin >> q;
        while(q--){
            int x,y;
            cin >> x >> y;
            cout << LCA(x,y) << "\n";
        }
    }



    return 0;
}
