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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n;

void solve(){
    if(n == 2){
        cout << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
        return;
    }
    if(n%4 == 0){
        cout << 0 << "\n";
        cout << n/2 << " ";
        for(int i=1;i<=n/2;i+=2){
            cout << i << " " << n-i+1 << " ";
        }
    }else if(n%4 == 1){
        cout << 1 << "\n";
        cout << n/2 << " ";
        for(int i=2;i<=n/2;i+=2){
            cout << i << " " << n-i+2 << " ";
        }
    }else if(n%4 == 2){
        cout << 1 << "\n";
        cout << n/2 << " ";
        cout << 1 << " ";
        for(int i=3;i<=n/2;i+=2){
            cout << i << " " << n-i+3 << " ";
        }
    }else if(n%4 == 3){
        cout << 0 << "\n";
        cout << 1+(n-3)/2 << " ";
        cout << 3 << " ";
        for(int i=4;i<=n/2+1;i+=2){
            cout << i << " " << n-i+4 << " ";
        }
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
