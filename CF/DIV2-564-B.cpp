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

int n;

void solve(){
    if(n == 1){
        cout << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
    }else if(n == 2){
        cout << 2 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 1 << " " << 2 << "\n";
    }else if(n == 3){
        cout << 2 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 1 << " " << 2 << "\n";
        cout << 2 << " " << 2 << "\n";
    }else if(n == 4){
        cout << 3 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 1 << " " << 3 << "\n";
        cout << 3 << " " << 1 << "\n";
        cout << 3 << " " << 3 << "\n";
    }else{
        int k = n/2+1;
        cout << k << "\n";
        forn(i,1,k)cout << 1 << " " << i << "\n";
        forn(i,2,n-k+1)cout << i << " " << k << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    solve();



    return 0;
}
