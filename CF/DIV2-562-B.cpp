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
int n,m;
pii a[N];

bool can(int x, int y){
    forn(i,1,m){
        if(x != a[i].ff && x != a[i].ss && y != a[i].ff && y != a[i].ss)
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,m)cin >> a[i].ff >> a[i].ss;

    bool flag = true;
    forn(i,2,m){
        if(a[i].ff != a[1].ff && a[i].ss != a[1].ff){
            if(can(a[1].ff,a[i].ff)){puts("YES");ex;}
            if(can(a[1].ff,a[i].ss)){puts("YES");ex;}
            flag = false; break;
        }
    }

    if(flag){puts("YES");ex;}

    flag = true;
    forn(i,2,m){
        if(a[i].ff != a[1].ss && a[i].ss != a[1].ss){
            if(can(a[1].ss,a[i].ff)){puts("YES");ex;}
            if(can(a[1].ss,a[i].ss)){puts("YES");ex;}
            flag = false; break;
        }
    }

    if(flag){puts("YES");ex;}

    puts("NO");



    return 0;
}
