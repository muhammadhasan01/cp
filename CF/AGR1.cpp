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
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int K = 1e5+3;
int b,k;
ll a[K];

string solve(){
    if(b%2 == 0){
        if(a[k]%2 == 0)return "even";
        else return "odd";
    }else{
        ll sum = 0;
        forn(i,1,k)sum += a[i];
        if(sum%2 == 0)return "even";
        else return "odd";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> b >> k;
    forn(i,1,k) cin >> a[i];
    cout << solve() << "\n";


    return 0;
}
