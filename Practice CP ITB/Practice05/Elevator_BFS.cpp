#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll F,S,G,U,D;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>F>>S>>G>>U>>D;
    ll dis[F+2];
    for(ll i=0; i < F+2; i++){
        dis[i] = inf;
    }
    ll X = S; dis[S] = 0;
    queue<ll> q;
    q.push(X);
    while(!q.empty()){
        X = q.front();
        q.pop();
        ll m[2] = {U,-D};
        for(int i=0; i<2; i++){
            ll Y = X+m[i];
            if(1 <= Y && Y <= F && dis[Y] > dis[X]+1){
                q.push(Y);
                dis[Y] = dis[X]+1;
            }
        }
    }
    if(dis[G] == inf){dis[G] = -1;}
    cout << dis[G] << "\n";
    return 0;
}
