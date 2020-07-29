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

// https://codeforces.com/blog/entry/18051

const int N = 100*1000;
int n;
int tree[2*N+3];

void build(){
    for(int i=n-1;i>0;i--){
        tree[i] = tree[2*i]+tree[2*i+1];
    }
}

void update(int p, int value){
    for(tree[p+=n] = value; p > 1; p/=2){
        tree[p/2] = tree[p]+tree[p^1];
    }
}

// query to add range [l,r)
int query(int l, int r){
    int sum = 0;
    for(l+=n, r+=n; l < r; l/=2, r/=2){
        cout << l << " " << r << "\n";
        if(l&1)sum += tree[l++];
        if(r&1)sum += tree[--r];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tree[n+i];
    }
    build();
    for(int i=1;i<=2*n-1;i++){
        cout << i << " => " << tree[i] << "\n";
    }
    int l, r;
    cin >> l >> r;
    cout << query(l-1,r) << "\n";
    int pos, val;
    cin >> pos >> val;
    // update takes index and value as the parameter
    update(pos-1,val);
    cout << "Updated -> " << tree[n+pos] << "\n";
    for(int i=1;i<=2*n-1;i++){
        cout << i << " => " << tree[i] << "\n";
    }
    return 0;
}
