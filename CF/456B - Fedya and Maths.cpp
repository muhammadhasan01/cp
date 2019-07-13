#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
using namespace std;


// find 1^n+2^n+3^n+4^n mod 5

ll ans(ll n){
    if(n%2==1){return 0;}else{
        ll k = n%4;
        return 2*(1+pow(2,k));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n;
    cout << ans(n)%5 << "\n";
    return 0;
}
