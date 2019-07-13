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

int n,k;
ll m, a[100003];

ll solve(){
    if(n == 1)return 1;
    if(k == 1)return a[n]-a[1]+1;

    priority_queue<ll> pq;

    forn(i,1,n-1)pq.push(a[i+1]-a[i]);

    ll ans = a[n]-a[1]+1;
    int cnt = 0;
    while(!pq.empty() && cnt != k-1){
        ans -= pq.top()-1;
        pq.pop();
        cnt++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    forn(i,1,n)cin >> a[i];
    cout << solve() << "\n";


    return 0;
}
