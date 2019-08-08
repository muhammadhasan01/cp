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
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 200*1000;
int t,n,q;
ll tree[2*NMAX+3];

void build(){
    for(int i=n-1;i>0;i--){tree[i]=tree[2*i]&tree[2*i+1];}
}

ll query(int l, int r){
    ll answer;
    bool first = true;
    for(l+=n,r+=n;l<r;l/=2,r/=2){
        if(l&1){
            if(first){
                answer = tree[l++]; first = false;
            }else{
                answer &= tree[l++];
            }
        }
        if(r&1){
            if(first){
                answer = tree[--r]; first = false;
            }else{
                answer &= tree[--r];
            }
        }
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n;
        form(n)cin>>tree[i+n];
        build();
        cin >> q;
        while(q--){
            int l,r; cin >> l >> r;
            cout << query(l-1,r) << "\n";
        }
    }

    return 0;
}
