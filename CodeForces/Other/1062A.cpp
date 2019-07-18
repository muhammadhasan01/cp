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

const int NMAX = 100;
int n;
int a[NMAX+3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    forn(n){
        cin >> a[i];
    }

    a[0] = 0, a[n+1] = 1001;

    int cnt = 0, ans = 0;
    for(int i=0;i<=n;i++){
        if(a[i+1]-a[i] == 1){
            cnt++;
        }else{
            cnt = 0;
        }
        ans = max(cnt-1,ans);
    }
    cout << ans << "\n";
    return 0;
}
