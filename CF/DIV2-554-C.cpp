#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll a,b;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    if(a > b)swap(a,b);
    ll x = b-a;
    ll ans = (1ll<<62), k = 0;
    ll temp,j,c,lcm;
    for(ll i=1;i*i<=x;i++){
        if(x%i == 0){
            j = i;
            if(a%j == b%j){
                if(a%j == 0){
                    temp = 0;
                }else{
                    temp = j - a%j;
                }
                lcm = (a+temp) * (b+temp)/j;
                if(lcm < ans){
                    k = temp;
                    ans = lcm;
                }
            }
            if(i*i != x){
                j = x/i;
                if(a%j == b%j){
                    if(a%j == 0){
                        temp = 0;
                    }else{
                        temp = j - a%j;
                    }
                    lcm = (a+temp) * (b+temp)/j;
                    if(lcm < ans){
                        k = temp;
                        ans = lcm;
                    }
                }
            }
        }
    }

    cout << k << "\n";


    return 0;
}
