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

ll n;

ll solve(){
    if(n == 1)return 0;
    if(n == 2)return 1;
    if(n == 3)return 3;
    if(n == 4)return 2;
    if(n == 5)return 5;
    if(n == 6)return 3;
    if(n == 7)return 7;
    if(n == 8)return 4;
    if(n&1){
        return n;
    }else{
        return n/2;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n++;

    cout << solve() << "\n";



    return 0;
}
