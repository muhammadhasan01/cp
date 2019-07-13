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

int l,r,x,y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> r >> x >> y;

    if(y%x != 0){puts("0"); ex;}
    int m = y/x;
    int ans = 0;
    for(int i=1;i*i<=m;i++){
        if(m%i == 0){
            if(__gcd(i,m/i) == 1){
                int k1 = i*x, k2 = (m/i)*x;
                if(l <= k1 && k1 <= r && l <= k2 && k2 <= r){
                    if(k1 == k2)ans++;
                    else ans += 2;
                }
                //cerr << k1 << " " << k2 << " => " << ans << "\n";
            }
        }
    }
    cout << ans << "\n";





    return 0;
}
