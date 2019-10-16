#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
#define mp make_pair
#define pb push_back
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n; ll a[n]; for(ll i=0;i<n;i++){cin>>a[i];}
    ll k = accumulate(a,a+n,0), sum = 0; if(k%2==1){k++;}
    for(ll i=0;i<n;i++){
        sum +=a[i];
        if(sum >= k/2){
            cout << i+1 << "\n";
            return 0;
        }
    }
    return 0;
}
