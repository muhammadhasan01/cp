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

const int N = 2e5;
int n,m;
vector<int> k(N+5);
pii q[N+5];

bool ok(int d){

    vector<int> last(n+3, -1);
    forn(i,1,m){
        if(q[i].ff <= d){
            last[q[i].ss] = max(last[q[i].ss],q[i].ff);
        }
    }

    vector<vector<int>> buy(N+5);
    forn(i,1,n){
        if(last[i] != -1)buy[last[i]].pb(i);
    }

    int mon = 0;
    vector<int> k1 = k;
    forn(i,1,d){
        mon++;
        if(i > N)continue;
        for(auto e:buy[i]){
            if(mon >= k1[e]){
                mon -= k1[e];
                k1[e] = 0;
            }else{
                k1[e] -= mon;
                mon = 0;
                break;
            }
        }
    }

    int price = 0;
    forn(i,1,n)price += 2*k1[i];

    //cerr << mon << " and " << price << "\n";

    return mon >= price;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n)cin >> k[i];
    forn(i,1,m)cin >> q[i].ff >> q[i].ss;

    int l = 1, r = 2*N;
    while(l <= r){
        int m = (l+r)/2;
        //cerr << l << "," << r << " and " << m << "\n";
        if(ok(m)){
            //cerr << "kenapa?\n";
            r = m-1;
        }else{
            //cerr << "naloh" << "\n";
            l = m+1;
        }
    }

    //cerr << l << " and " << r << "\n";

    forn(i,r,l){
        if(ok(i)){
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
