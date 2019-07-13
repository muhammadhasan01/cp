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

const int N = 3e5+5;
int n;
ll a[N],f[N],g[N],sp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int maxi = 1;
    cin >> n;
    forn(i,1,n){
        string k;
        cin >> k;
        int x = 0;
        string m = "";
        if(k[0] == '(')x++;
        else x--;
        m.pb(k[0]);
        forn(i,1,len(k)-1){
            if(!(m.empty()) && m.back() == '(' && k[i] == ')'){
                x--;
                m.pop_back();
            }else{
                m.pb(k[i]);
                if(k[i] == '(')x++;
                else x--;
            }
        }


        bool flag = true;
        forn(i,0,len(m)-2)if(m[i] != m[i+1])flag = false;
        
        if(!flag)continue;
        if(x == 0){
            sp++;
        }else if(x > 0){
            f[x]++;
        }else if(x < 0){
            g[-x]++;
        }
        maxi = max(maxi, abs(x));
    }

    ll ans = sp * sp;
    forn(i,1,maxi)ans += f[i] * g[i];

    cout << ans << "\n";







    return 0;
}
