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

// problem link https://www.hackerrank.com/challenges/dijkstrashortreach/problem
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

int t,n,m,x,y,s,e,r;

void Djikstra(vector<pii> a[]){
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    vector<int> dist(n+2,inf);
    dist[s] = 0;
    pq.push(mp(dist[s],s));
    while(!pq.empty()){
        int u = pq.top().ss;
        pq.pop();

        for(int j=0; j<a[u].size(); j++){
            int v = a[u][j].ff;
            int weight = a[u][j].ss;
            if(dist[v] > dist[u]+weight){
                //cout << v << " => " << dist[u]+weight << "\n";
                dist[v] = dist[u]+weight;
                pq.push(mp(dist[v],v));
            }
        }
    }
    if(dist[e] == inf){
        cout << "NO\n";
    }else{
        cout << dist[e] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<pii> a[n+2];
        for(int i=1; i<=m;i++){
            cin >> x >> y >> r;
            a[x].pb(mp(y,r));
            a[y].pb(mp(x,r));
        }
        /*for(int i=1;i<=n;i++){
            for(int j=0; j<a[i].size();j++){
                cout << i << "," << a[i][j].ff << " => " << a[i][j].ss << "\n";
            }
        }*/
        cin >> s >> e;
        Djikstra(a);
    }

    return 0;
}
