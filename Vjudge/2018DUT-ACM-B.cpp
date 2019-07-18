#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define maximal 1000000000
using namespace std;

const int NMAX = 200*1000;
int n,k;
ll a[NMAX+3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(k==0){
        if(a[1] == 1){
            cout << "-1\n"; return 0;
        }else{
            cout << 1 << "\n"; return 0;
        }
    }
    //for(int i=1;i<=n;i++){
    //    cout << a[i] << " ";
    //}cout << "\n";
    ll ans = a[k], p = 0;
    for(int i=1;i<=n;i++){
        if(ans >= a[i])p++;
    }
    if(p == k && 1 <= ans && ans <= maximal){
        cout << ans << "\n";
    }else{
        cout << -1 << "\n";
    }
    return 0;
}
