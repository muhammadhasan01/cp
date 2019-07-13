#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define pf push_front
using namespace std;

const int N = 2*100*1000;
int n;
vector<ll> tree(2*N,0);

void build(){
    for(int i=N-1;i>0;i--){
        tree[i] = tree[2*i]+tree[2*i+1];
    }
}

void update(int p, ll val){
    for(tree[p] = val; p > 1; p/=2) tree[p/2] = tree[p]+tree[p^1];
}

ll query(int l, int r){
    ll sum = 0;
    for(l+=N, r+=N; l<r; l/=2, r/=2){
        //cout << l << " " << r << " => ";
        if(l&1){sum+=tree[l++];}
        if(r&1){sum+=tree[--r];}
        //cout << sum << "\n";
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        //cout << 2*N-n+i << "\n";
        cin >> tree[2*N-n+i];
    }
    build();
    int q; cin >> q;
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int l,r;
            cin >> l >> r;
            l = N-n+l, r = N-n+r;
            //cout << l << " " << r << "\n";
            cout << query(l,r+1) << "\n";
        }else{
            ll val;
            cin >> val;
            //cout << 2*N-n << "\n";
            update(2*N-n,val);
            //cout << "Updated => " << tree[2*N-n] << "\n";
            n++;
        }
    }
    return 0;
}
