#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pqg priority_queue<long long, vector<long long>, greater<long long> >
#define pql priority_queue<long long>
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// problem : Problem IIT Challenge "Dracula" on cp.if.itb.ac.id
// https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/
// https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/

ll n, m, u, v, w;
int s = 1; // let this be the source of the vertex

ll minSpanningTree(vector<pll> a[]){

    ll mst = 0;

    priority_queue<pll, vector<pll>, greater<pll> > pq;

    // create a vector key and initialize all of it to inf
    vector<ll> key(n+2,inf);

    // to store a parent which in turn store MST (optional)
    vector<ll> parent(n+2,-1);

    // To keep track of vertices included in MST
    vector<bool> inMST(n+2,false);

    pq.push(mp(0,s));
    key[s] = 0;
    while(!pq.empty()){
        int u = pq.top().ss;
        pq.pop();

        // include vertex u to the MST
        inMST[u] = true;

        for(int j=0; j<a[u].size();j++){
            int v = a[u][j].ff;
            int weight = a[u][j].ss;

            // if v is not yet in MST and weight of (u,v) is smaller
            // than the current key of v
            if(inMST[v] == false && key[v] > weight){
                // update the key[v]
                key[v] = weight;
                pq.push(mp(key[v],v));
                parent[v] = u;
            }
        }
    }

    // print edges of MST using parent array
    for (int i=1;i<=n;i++){
        cout << i << " => " << parent[i] << " => " << key[i] << "\n";
        mst += key[i];
    }
    return mst;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<pll> a[n+2];
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }

    cout << minSpanningTree(a) << "\n";

    return 0;
}
