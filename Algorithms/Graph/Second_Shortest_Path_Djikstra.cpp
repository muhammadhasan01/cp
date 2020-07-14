#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf 123456789
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define maximal 100000
using namespace std;

const int MAXN = 5000;
int N,R,A,B,D, s = 1;
vector<pii> a[MAXN+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R;
    for(int i=1;i<=R;i++){
        cin >> A >> B >> D;
        a[A].pb(mp(B,D));
        a[B].pb(mp(A,D));
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<int> D(N+2, maximal);
    vector<int> D2(N+2, maximal);
    D[1] = 0;
    pq.push(mp(D[1],1));
    while(!pq.empty()){
        int w = pq.top().ff;
        int u = pq.top().ss;
        pq.pop();
        if(D2[u] < w)continue;
        for(int j=0; j<a[u].size(); j++){
            int node = a[u][j].ff;
            int weight = a[u][j].ss;
            int d = weight + w;
            if(d < D[node]){
                swap(d,D[node]);
                pq.push(mp(D[node],node));
            }
            if(D2[node] > d){
                D2[node] = d;
                pq.push(mp(D2[node],node));
            }
        }
    }
    cout << D2[N] << "\n";
    return 0;
}
