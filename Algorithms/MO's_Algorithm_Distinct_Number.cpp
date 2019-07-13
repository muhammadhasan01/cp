#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x.begin(),x.begin()+(int)n)
#define nsort(x,n) sort(x.begin()+1,x.begin()+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 30*1000;
const int QMAX = 200*1000;
const int VMAX = 1000*1000;
int n,q,block,ans;
vector<int> a(NMAX+3);
int m[VMAX+3];

struct s{
    int l,r,idx;
};

vector<s> v(QMAX+3);
vector<int> quer(QMAX+3);

bool cmpr(s a, s b){
    if(a.l/block != b.l/block){
        return a.l/block < b.l/block;
    }
    return a.r/block < b.r/block;
}

void add(int i){
    m[a[i]]++;
    if(m[a[i]] == 1)ans++;
}

void remove(int i){
    m[a[i]]--;
    if(m[a[i]] == 0)ans--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    form(n)cin>>a[i];
    cin >> q;
    form(q){
        int l,r;
        cin >> l >> r;
        v[i].l = l-1, v[i].r = r-1, v[i].idx = i;
    }
    block = sqrt(n);
    sort(v.begin(),v.begin()+q,cmpr);
    int cl = 0, cr = 0;
    form(q){
        int x = v[i].l, y = v[i].r;
        while(cl < x){
            remove(cl); cl++;
        }
        while(cl > x){
            add(cl-1); cl--;
        }
        while(cr <= y){
            add(cr); cr++;
        }
        while(cr > y+1){
            remove(cr-1); cr--;
        }
        cerr << cl << " " << cr << " => " << ans << "\n";
        quer[v[i].idx] = ans;
    }
    form(q){
        cout << quer[i] << "\n";
    }
    return 0;
}
