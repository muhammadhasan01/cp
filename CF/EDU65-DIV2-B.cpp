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

map<int, pair<int,int> > m;
vector<int> a = {4,8,15,16,23,42};

bool f[45];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //cout << m[1].ff << " " << m[1].ss << "\n";
    int n = len(a)-1;
    forn(i,0,n){
        forn(j,i+1,n){
            int x = a[i];
            int y = a[j];
            m[x*y] = mp(x,y);
        }
    }


    int ans[10];
    int r1,r2,r3,r4;
    cout << "? 1 2" << "\n";
    cout << flush;


    cin >> r1;

    cout << "? 2 3" << "\n";
    cout << flush;

    cin >> r2;

    //cerr << r1 <<" " << r2 << " wtf" << "\n";

    pii p = m[r1], q = m[r2];
    if(p.ff == q.ff || p.ff == q.ss){
        ans[2] = p.ff;
    }else if(p.ss == q.ff || p.ss == q.ss){
        ans[2] = p.ss;
    }

    //cout << ans[2] << "\n";

    ans[1] = r1/ans[2];
    ans[3] = r2/ans[2];
    cout << "? 3 4" << "\n";
    cout << flush;

    cin >> r3;

    ans[4] = r3/ans[3];

    cout << "? 4 5" << "\n";
    cout << flush;

    cin >> r4;
    ans[5] = r4/ans[4];

    forn(i,1,5)f[ans[i]] = 1;
    for(auto e:a){
        if(f[e] == 0)ans[6] = e;
    }

    cout << "! ";
    forn(i,1,6)cout << ans[i] << " ";
    cout << flush;


    return 0;
}
