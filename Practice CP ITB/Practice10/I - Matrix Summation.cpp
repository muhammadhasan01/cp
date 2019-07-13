#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1024;
ll bit[N+2][N+2];
int n;

ll sum(int x, int y){
    ll res = 0;
    for(;x>0;x-=(x&-x)){
        for(int j=y;j>0;j-=(j&-j)){
            res += bit[x][j];
        }
    }
    return res;
}

ll sum_query(int x1, int y1, int x2, int y2){
    return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
}

void update(int x, int y, ll val){
    ll tmp = val-sum_query(x,y,x,y);
    for(;x<=n;x+=(x&-x)){
        for(int j=y;j<=n;j+=(j&-j)){
            bit[x][j] += tmp;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc; cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                bit[i][j] = 0;
            }
        }
        while(true){
        string st;
        cin >> st;
        if(st == "SET"){
            int x,y; ll val; cin >> x >> y >> val;
            update(x+1,y+1,val);
        }else if(st == "SUM"){
            int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            cout << sum_query(x1+1,y1+1,x2+1,y2+1) << "\n";
        }else if(st == "END"){
            break;
        }
    }
    }
}
