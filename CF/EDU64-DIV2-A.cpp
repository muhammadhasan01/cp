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

const int N = 105;
int n;
int a[N];

void solve(){
    int ans = 0;

    forn(i,2,n-1){
        if(a[i-1] == 3 && a[i] == 1 && a[i+1] == 2)ans--;
    }

    forn(i,1,n-1){
        int x = a[i], y = a[i+1];
        if(x > y)swap(x,y);
        if(x == 1 && y == 3){
            ans += 4;
        }else if(x == 1 && y == 2){
            ans += 3;
        }else if(x == 2 && y == 3){
            cout << "Infinite\n";
            return;
        }
    }

    cout << "Finite" << "\n";
    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin >> a[i];
    solve();



    return 0;
}
