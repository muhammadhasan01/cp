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
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 5e5+5;
int n,k,d;
int a[N], dp[N], t[4*N];

void build(int v, int s, int e){
    if(s == e){
        t[v] = dp[s];
    }else{
        int m = (s+e)/2;
        build(2*v,s,m);
        build(2*v+1,m+1,e);
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

void update(int v, int s, int e, int pos, int x){
    if(s == e){
        t[v] = x;
        dp[pos] = x;
    }else{
        int m = (s+e)/2;
        if(pos <= m){
            update(2*v,s,m,pos,x);
        }else{
            update(2*v+1,m+1,e,pos,x);
        }
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

int get(int v, int s, int e, int l, int r){
    //cerr << v  << " => " << s << " and " << e << "\n";
    if(r < s || e < l){
        return 0;
    }
    if(l <= s && e <= r){
        return t[v];
    }

    int m = (s+e)/2;
    int k1 = get(2*v,s,m,l,r);
    int k2 = get(2*v+1,m+1,e,l,r);
    return max(k1,k2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> d;
    forn(i,1,n)cin >> a[i];

    sort(a+1,a+1+n);

    dp[1] = 1;
    build(1,1,n+1);

    int j = 1;
    forn(i,1,n){
        while(j < i && a[i] - a[j] > d)j++;
        if(j > i-k+1)continue;
        int x = get(1,1,n+1,j,i-k+1);
        dp[i+1] = (x == 1);
        if(dp[i+1])update(1,1,n+1,i+1,1);
    }


    puts(dp[n+1] ? "YES" : "NO");





    return 0;
}
