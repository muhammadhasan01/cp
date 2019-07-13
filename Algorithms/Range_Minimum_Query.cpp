#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
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
using namespace std;

int n,m;
vector<int> tree;

void build(){
    for(int i=n-1;i>0;i--){
        tree[i] = min(tree[2*i],tree[2*i+1]);
        //cout << tree[i] << " => " << tree[2*i] << "," << tree[2*i+1] << "\n";
    }
}

int query(int l, int r){
    int res = inf;
    for(l+=n, r+=n; l < r; l/=2, r/=2){
        //cout << l << "," << r << " => ";
        if(l&1)res = min(res,tree[l++]);
        if(r&1)res = min(res,tree[--r]);
        //cout << res << "\n";
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    tree.resize(2*n);
    for(int i=0;i<n;i++){
        cin >> tree[i+n];
    }
    build();
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        if(l>r)swap(l,r);
        cout << query(l,r+1) << "\n";
    }

    return 0;
}
