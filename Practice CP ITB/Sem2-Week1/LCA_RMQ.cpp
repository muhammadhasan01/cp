#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1005;
int n,q,tc;
vector<int> g[N], euler;
int first[N], height[N];
bitset<N> vis;
vector<int> tree;

void dfs(vector<int> g[], int v, int h){
    vis[v] = 1;
    height[v] = h;
    first[v] = euler.size();
    euler.pb(v);
    for(auto e:g[v]){
        if(vis[e] == 0){
            dfs(g, e, h+1);
            euler.pb(v);
        }
    }
}

void build(int v, int s, int e){
    if(s == e){
        tree[v] = euler[s];
    }else{
        int m = (s+e)/2;
        build(2*v,s,m);
        build(2*v+1,m+1,e);
        int l = tree[2*v], r = tree[2*v+1];
        tree[v] = (height[l] < height[r]) ? l : r;
    }
}

int query(int v, int s, int e, int l, int r){
    if(s > r || l > e){
        return -1;
    }
    if(l <= s && e <= r){
        return tree[v];
    }

    int m = (s+e)/2;
    int left = query(2*v,s,m,l,r);
    int right = query(2*v+1,m+1,e,l,r);
    if(left == -1)return right;
    if(right == -1)return left;
    return (height[left] < height[right])? left:right;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    forn(t,1,tc){
        cin >> n;

        vector<int> g[N];
        euler.clear();
        vis.reset();
        tree.clear();
        MEM(first, 0);
        MEM(height, 0);

        forn(i,1,n){
            int x;
            cin >> x;
            forn(k,1,x){
                int y;
                cin >> y;
                g[i].pb(y);
                g[y].pb(i);
            }
        }

        dfs(g,1,0);
        //for(auto e:euler){
        //    cout << e << " => " << height[e] << " => " << first[e] << "\n";
        //}cout << "\n";

        tree.resize(4*euler.size());
        build(1,0,euler.size()-1);


        cout << "Case " << t << ":\n";
        cin >> q;
        while(q--){
            int x,y;
            cin >> x >> y;
            int l = first[x], r = first[y];
            if(l > r)swap(l,r);
            //cout << l << " " << r << "\n";
            cout << query(1,0,euler.size()-1,l,r) << "\n";
        }
    }



    return 0;
}
