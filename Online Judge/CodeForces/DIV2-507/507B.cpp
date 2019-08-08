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
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,k;

void solve(){

    int x = 2*k+1;

    if(n%x == 0){
        cout << n/x << "\n";
        for(int i=k+1;i<=n;i+=x){
            cout << i << " ";
        }
    }else if(x < n){
        cout << n/x+1 << "\n";
        deque<int> s;
        for(int i=1;i<=n;i+=x)s.pb(i);
        int st = 0;
        if(s.back()+k < n){
            st = n - (s.back()+k);
        }
        for(auto x:s){
            cout << x+st << " ";
        }
    }else if(x > n){
        cout << 1 << "\n" << n/2+1 << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    solve();


    return 0;
}
