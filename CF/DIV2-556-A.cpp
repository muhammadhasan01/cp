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

int n,r,m;
int s[35], b[35];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
    int mini = inf, maxi = -1;
    forn(i,1,n){
        cin >> s[i];
        mini = min(mini, s[i]);
    }
    forn(i,1,m){
        cin >> b[i];
        maxi = max(maxi, b[i]);
    }

    int ans = r;
    int temp = r%mini + maxi * (r/mini);
    //cerr << ans << " " << temp << "\n";
    ans = max(ans, temp);
    cout << ans << "\n";



    return 0;
}
