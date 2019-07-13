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
#define csort(x,n) sort(x.begin()+1,x.begin()+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 200*1000;
ll a[N+3], bit[N+3];
int n,q;

void update(int x, ll val){
    for(;x<=N;x+=(x&-x)){
        bit[x] += val;
    }
}

ll query(int x){
    ll sum = 0;
    for(;x>0;x-=(x&-x)){
        sum += bit[x];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    MEM(bit,0);
    for(int i=1;i<=n;i++){
        cin >> a[N-n+i];
        update(N-n+i,a[N-n+i]);
    }
    cin >> q;
    while(q--){
        int k,l,r;
        cin >> k;
        if(k==1){
            cin >> l >> r;
            l = N-n+l, r = N-n+r;
            cout << query(r)-query(l-1) << "\n";
        }else{
            cin >> l;
            update(N-n,l);
            n++;
        }
    }
    return 0;
}
