#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

// n -> number of vertices
// m -> number of edges
int t,n,m,x,y,s,r,d;

bool BellmanFord(pair<int,pii> a[]){

    vector<int> dist(n+2,inf);
    dist[s] = 0;

    for(int i=1; i<=n-1;i++){
        for(int j=1; j<=m; j++){
            int u = a[j].ss.ff; // source
            int v = a[j].ss.ss; // destination
            int w = a[j].ff; // weight
            if(dist[u] != inf && dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
            }
        }
    }
    if(dist[d]==inf)dist[d] = 0;
    cout << dist[d] << "\n";

    // checking for negative cycle
    for(int j=1; j<=m; j++){
        int u = a[j].ss.ff;
        int v = a[j].ss.ss;
        int w = a[j].ff;
        if(dist[u] != inf && dist[v] > dist[u]+w){
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> m;
        pair<int,pii> a[m+2];
        for(int i=1; i<=m;i++){
            cin >> x >> y >> r;
            a[i] = mp(r,mp(x,y));
        }
        cin >> s >> d;
        BellmanFord(a);
    }

    return 0;
}
