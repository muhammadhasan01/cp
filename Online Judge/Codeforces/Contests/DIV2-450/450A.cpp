#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<n;i++)
#define forn(n) for(int i=1;i<=n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,m;
deque<pii> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    forn(n){
        int x;
        cin >> x;
        dq.pb(mp(x,i));
    }
    int val, idx;
    while(!dq.empty()){
        val = dq.front().ff, idx = dq.front().ss;
        if(m < val){
            dq.pb(mp(val-m,idx));
        }
        dq.pop_front();
    }
    cout << idx << "\n";
    return 0;
}
