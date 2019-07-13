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

ll fastexpo(ll x, ll y){
    ll res = 1;
    while(y > 0){ // if y is odd
        if(y & 1){
            res *= x;
            res %= 11111;
        }
        y = y>>1; // y/2;
        x = (x*x)%11111;
    }
    return res%11111;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fastexpo(1111,2019) << "\n";


    return 0;
}
