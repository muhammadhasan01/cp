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

struct s{
    int le, ri, val;
};

const int NMAX = 100*1000;
int n;
s a[NMAX+3];
int dp[NMAX+3];

bool cmp(s a, s b){
    return a.ri < b.ri;
}

int find(int x){
    int l=1, r = x-1;
    while(l<=r){
        int mid = (l+r)/2;
        //cout << x << "," << l << "," << r << "," << mid << "\n";
        if(a[mid].ri < a[x].le){
            if(a[mid+1].ri < a[x].le){
                l = mid+1;
            }else{
                return mid;
            }
        }else{
            r = mid-1;
        }
    }
    return -1;
}

int solve(){
    dp[1] = a[1].val;
    for(int i=2;i<=n;i++){
        int x = a[i].val;
        int j = find(i);
        if(j!=-1){
            x += dp[j];
        }
        dp[i] = max(x,dp[i-1]);
        //cout << i << " => " << dp[i] << "\n";
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    forn(n){
        cin >> a[i].le >> a[i].ri >> a[i].val;
    }
    sort(a+1,a+1+n,cmp);
    /*cout << "\n";
    forn(n){
        cout << a[i].le << " " << a[i].ri << " " << a[i].val << "\n";
    }cout << "\n";*/
    cout << solve() << "\n";
    return 0;
}
