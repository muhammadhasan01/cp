#include <bits/stdc++.h>

// author : mastre

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 100009;

int n;
vector <pii> adl[N];
vector <pair<ll, pii>> edge;
int par[N];
ll sz[N];
ll tot;

int find(int a){
    if (par[a]==a) return a;
    return par[a] = find(par[a]);
}

ll tmp;
void make(int a, int b){
    a=find(a);
    b=find(b);

    if (a==b) return;
    if (sz[a]<sz[b]) swap(a,b);
    tot+=(sz[a]*sz[b])%MOD*tmp%MOD;
    tot%=MOD;

    sz[a]+=sz[b];
    par[b]=a;
}

void setup(){
    for (int i=0;i<N;i++){
        par[i]=i;
        sz[i]=1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n-1;i++){
        int a,b,w;
        cin >> a >> b >> w;
        // adl[a].pb(mp(b,w));
        // adl[b].pb(mp(a,w));
        edge.pb(mp(w,mp(a,b)));
    }

    setup();

    sort(edge.begin(), edge.end());

    for (auto x : edge){
    //    cout << x.se.fi << " " << x.se.se << el;
        tmp=x.fi;
        make(x.se.fi,x.se.se);
    }

    cout << tot << el;

    return 0;
}
