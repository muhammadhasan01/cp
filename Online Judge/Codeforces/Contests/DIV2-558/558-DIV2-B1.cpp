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
int n;
vector<pii> f(10);
int u[N];

bool cmpr(pii x, pii y){
    return x.ss > y.ss;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin >> u[i];
    int x = 1;
    forn(i,0,9)f[i].ff = i;
    forn(i,1,n){
        f[u[i]%10].ss++;
        vector<pii> q = f;
        bool flag = true;
        bool ch = false;
        sort(all(q),cmpr);
        int sm = q[0].ss;
        if(sm > q[1].ss && q[1].ss != 0){
            ch = true;
            sm--;
        }
        forn(j,1,9){
            if(q[j].ss == 0)break;

            if(j == 9 && !ch){q[j].ss--;}
            else if(j < 9 && q[j+1].ss == 0 && !ch){q[j].ss--;}

            if(q[j].ss != 0 && q[j].ss != sm){
                flag = false;
                break;
            }
        }
        if(flag)x = max(x,i);
    }
    cout << x << "\n";


    return 0;
}
