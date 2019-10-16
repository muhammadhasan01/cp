#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;

// Find the biggest LCM by choosing 3 integers below or the same as n

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n;
    if(n==1){cout << "1\n";}
    else if(n==2){cout << "2\n";}
    else if(n==3){cout << "6\n";}
    else if(n%2==1 && n >=5){
        cout << n*(n-1)*(n-2) << "\n";
    }else if(n%2==0 && n >= 4){
        ll x = __gcd(n,n-3);
        cout << max(n*(n-1)*(n-3)/x,max((n-1)*(n-2)*(n-3),n*(n-1)*(n-3)/2)) << "\n";
    }
    return 0;
}
