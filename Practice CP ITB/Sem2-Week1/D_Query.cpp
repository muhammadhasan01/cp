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

int n, a[30004], Q;
int m[1000003];
pair<pii,int> q[200003];
int ansq[200003];
int block;

bool compare(pair<pii,int> a, pair<pii,int> b){
    if(a.ff.ff/block != b.ff.ff/block){
        return a.ff.ff/block < b.ff.ff/block;
    }
    return a.ff.ss/block < b.ff.ss/block;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin >> a[i];
    cin >> Q;
    forn(i,1,Q){
        cin >> q[i].ff.ff >> q[i].ff.ss;
        q[i].ss = i;
    }
    block = sqrt(n);
    sort(q+1,q+1+Q,compare);
    int cl = 1, cr = 1, ans = 0;
    forn(i,1,Q){
        int x = q[i].ff.ff, y = q[i].ff.ss;
        while(cl < x){
            m[a[cl]]--;
            if(m[a[cl]] == 0){
                ans--;
            }
            cl++;
        }
        while(cl > x){
            m[a[cl-1]]++;
            if(m[a[cl-1]] == 1){
                ans++;
            }
            cl--;
        }
        while(cr <= y){
            m[a[cr]]++;
            if(m[a[cr]] == 1){
                ans++;
            }
            cr++;
        }
        while(cr > y+1){
            m[a[cr-1]]--;
            if(m[a[cr-1]] == 0){
                ans--;
            }
            cr--;
        }
        //cerr << cl << " " << cr << " => " << ans << "\n";
        ansq[q[i].ss] = ans;
    }

    forn(i,1,Q){
        cout << ansq[i] << "\n";
    }

    return 0;
}
