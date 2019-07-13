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

ll n, m, u, v, w;
int s = 1;

ll minSpanningTree(vector<pll> a[]){

    ll mst = 0;

    priority_queue<pll, vector<pll>, greater<pll> > pq;

    vector<ll> key(n+2,inf);

    vector<ll> parent(n+2,-1);

    vector<bool> inMST(n+2,false);

    pq.push(mp(0,s));
    key[s] = 0;
    while(!pq.empty()){
        int u = pq.top().ss;
        pq.pop();

        inMST[u] = true;

        for(int j=0; j<a[u].size();j++){
            int v = a[u][j].ff;
            int weight = a[u][j].ss;

            if(inMST[v] == false && key[v] > weight){
                key[v] = weight;
                pq.push(mp(key[v],v));
                parent[v] = u;
            }
        }
    }

    // print edges of MST using parent array
    for (int i=1;i<=n;i++){
        cout << i << " => " << parent[i] << " => " << key[i] << "\n";
        if(i!=s)mst += key[i];
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
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            cout << i << "," << a[i][j].ff << " => " << a[i][j].ss << "\n";
        }
    }*/
    cout << minSpanningTree(a) << "\n";

    return 0;
}
