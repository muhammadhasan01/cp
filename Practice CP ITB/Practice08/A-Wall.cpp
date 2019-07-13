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

const int N = 10;
int H, W, temp, s = 1;
vector<pii> a[N+2];
vector<int> dis(N+2,inf);

void Djikstra(){

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    dis[s] = 0;
    pq.push(mp(dis[s],s));
    while(!pq.empty()){
        int u = pq.top().ss;
        pq.pop();
        for(int j=0;j<a[u].size();j++){
            int v = a[u][j].ff;
            int w = a[u][j].ss;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                pq.push(mp(dis[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> temp;
            a[j].pb(mp(i,temp));
        }
    }
    Djikstra();
    int MP = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> temp;
            //cout << temp << " ";
            if(temp == -1 || temp == 1){continue;}else{
                MP += dis[temp];
            }
        }//cout << "\n";
    }
    cout << MP << "\n";
    return 0;
}
