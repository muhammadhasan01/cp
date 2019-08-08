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

const int N = 1000;
bitset<N> vis;
int f[105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    for(int i=2;i*i<=N;i++){
        if(vis[i] == 0){
            for(int j=2*i;j<=N;j+=i)vis[j] = 1;
        }
    }

    forn(i,2,N){
        if(vis[i] == 0)v.pb((ll)i);
        if(len(v) == 100)break;
    }

    int sum = 0;
    int cnt = 1;
    for(auto e:v){
        sum += e;
        //cerr << e << '\n';
        f[cnt] = sum;
        cnt++;
    }

    int n;
    cin >> n;
    forn(i,1,n){
        int x;
        cin >> x;
        cout << f[x] << "\n";
    }

    return 0;
}
