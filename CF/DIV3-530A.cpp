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

int n,x,y;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y >> s;
    int cnt = 0, ans = 0;
    for(int i=n-1;i>=0;i--){
        if(cnt < y || (cnt > y && cnt < x)){
            if(s[i] == '1')ans++;
        }else if(cnt == y){
            if(s[i] == '0')ans++;
        }
        //cerr << i << " => " << ans << "\n";
        if(cnt == x)break;
        cnt++;
    }
    cout << ans << "\n";

    return 0;
}
