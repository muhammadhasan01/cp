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

int tc;
ll n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n;
        int ans = 0;
        while(n != 1){
            if(n%5 == 0){
                n /= 5;
                n *= 4;
            }else if(n%3 == 0){
                n /= 3;
                n *= 2;
            }else if(n%2 == 0){
                n /= 2;
            }else{
                ans = -1; break;
            }
            ans++;
        }
        cout << ans << "\n";
    }



    return 0;
}
