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


// find the biggest s(A)+S(B), where A+B = n

ll s(ll n){
    ll k=0;while(n!=0){k+=n%10;n/=10;}return k;
}

ll ans(ll n){
    if(n<=18)return n;
    ll temp = n, k, c = log10(n);
    while(temp>9){
        temp/=10;
        k = temp%10;
    }
    k = k*pow(10,c)-1;
    return max(s(n),s(k)+s(n-k));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n;
    cout << ans(n) << "\n";
    return 0;
}
