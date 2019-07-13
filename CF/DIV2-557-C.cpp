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

const int N = 1e5+5;
int n,k;
int x[N], f[N], le[N], ri[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    forn(i,1,k)cin >> x[i];

    ll tot = 3*n - 2;


    map<pll, int> m;

    forn(i,1,k){
        f[x[i]]++;
        if(f[x[i]] == 1)tot--;

        if(f[x[i] + 1] > 0 && m[{x[i]+1,x[i]}] == 0){
            m[{x[i]+1,x[i]}] = 1;
            tot--;
        }

        if(f[x[i] - 1] > 0 && m[{x[i]-1,x[i]}] == 0){
            m[{x[i]-1,x[i]}] = 1;
            tot--;
        }

    }

    cout << tot << "\n";



    return 0;
}
