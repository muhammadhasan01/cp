#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define rofn(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll n;

ll solve(){
    if(n%4 == 0){
        return 0;
    }else if(n%4 == 1){
        return 1;
    }else if(n%4 == 2){
        return 1;
    }else if(n%4 == 3){
        return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << solve() << "\n";


    return 0;
}
