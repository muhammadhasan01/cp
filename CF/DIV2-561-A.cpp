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
int c[30];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        string s; cin >> s;
        c[s[0] - 'a']++;
    }

    int ans = 0;
    forn(i,0,25){
        int x = c[i]/2;
        ans += (x * (x-1))/2;
        int y = c[i] - x;
        ans += (y * (y-1))/2;
    }

    cout << ans << "\n";


    return 0;
}
