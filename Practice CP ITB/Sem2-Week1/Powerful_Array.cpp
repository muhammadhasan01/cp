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
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 200*1000+5;
int n,t;
pair<int,pii> q[N];
int m[1000005], block;
ll a[N],ans[N];

bool compare(pair<int,pii> x, pair<int,pii> y){
    if(x.ss.ff/block != y.ss.ff/block){
        return x.ss.ff/block < y.ss.ff/block;
    }
    return x.ss.ss/block < y.ss.ss/block;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    forn(i,1,n)cin >> a[i];
    forn(i,1,t){
        cin >> q[i].ss.ff >> q[i].ss.ss;
        q[i].ff = i;
    }
    block = sqrt(n);
    sort(q+1,q+1+t,compare);
    ll sum = 0;
    int cl = 1, cr = 1;
    forn(i,1,t){
        int x = q[i].ss.ff, y = q[i].ss.ss;
        //cerr << cl << " " << cr << ":\n";
        //cerr << i << " => " << x << " => " << y << " => " << sum << " --> ";
        while(cl < x){
            sum -= a[cl]*(2*m[a[cl]]-1);
            m[a[cl]]--;
            cl++;
            //cerr << cl << "\n";
        }

        while(cl > x){
            sum += a[cl-1]*(2*m[a[cl-1]]+1);
            m[a[cl-1]]++;
            cl--;
            //cerr << cl << "\n";
        }

        //if(cr <= y){cerr<<"QNWIDNWI\n";}

        while(cr <= y){
            sum += a[cr]*(2*m[a[cr]]+1);
            m[a[cr]]++;
            cr++;
        }

        while(cr > y+1){
            sum -= a[cr-1]*(2*m[a[cr-1]]-1);
            m[a[cr-1]]--;
            cr--;
        }

        //cerr << sum << "\n";
        //cerr << x << " lah " << y << "\n";
        ans[q[i].ff] = sum;
    }

    //cerr << "NANI\n";
    forn(i,1,t){
        cout << ans[i] << "\n";
    }

    return 0;
}
