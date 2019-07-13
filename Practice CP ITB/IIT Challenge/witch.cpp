#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define first ff
#define second ss
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;
    ll c = 0;
    for(ll i=0;i*i*i*i<=x;i++){
        for(ll j=0; j*j*j<=x-i*i*i*i; j++){
            if(x-i*i*i*i-j*j*j >= 0){
                //cout << i << "," << j << "\n";
                c += int(sqrt(x-i*i*i*i-j*j*j))+1;
            }
        }
    }
    cout << c << "\n";
    return 0;
}
