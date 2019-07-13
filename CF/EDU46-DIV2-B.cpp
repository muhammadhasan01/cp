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

const int N = 1e5+5;
int n;
ll a[N], m;
ll pre[N], erp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n)cin >> a[i];
    a[0] = 0, a[n+1] = m;
    forn(i,0,n+1){
        if(i&1){
            pre[i] = pre[i-1] + a[i] - a[i-1];
        }else{
            if(i != 0)pre[i] = pre[i-1];
        }
    }

    ll ans  = pre[n+1];

    int cnt = 1;
    nrof(i,n+1,0){
        if(i&1){
            if(i == n+1)continue;
            erp[i] = erp[i+1] + a[i+1] - a[i];
        }else{
            erp[i] = erp[i+1];
        }
    }

    ll ins;
    forn(i,0,n){
        if(i&1){
            ins = a[i] + 1;
            if(ins != a[i+1]){
                ans = max(ans, pre[i] + a[i+1] - ins + erp[i+2]);
            }
        }else{
            ins = a[i+1] - 1;
            if(ins != a[i]){
                ans = max(ans, pre[i-1] + ins - a[i] + erp[i+1]);
            }
        }
    }

    cout << ans << "\n";




    return 0;
}
