#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define maksimal 1000000000
using namespace std;

const int N = 5;
ll n, w;
ll p[N+2];

ll kpk(ll a, ll b){
    return (a*b)/__gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--){
        cin >> w;
        for(int i=1;i<=w;i++)cin>>p[i];
        ll ans = 1;
        for(int i=1;i<=w;i++){
            ans = kpk(ans,p[i]);
            if(ans > maksimal){
                cout << "More than a billion.\n";
                ans = -1;
                break;
            }
        }
        if(ans != -1){
            cout << ans << "\n";
        }
    }
    return 0;
}
