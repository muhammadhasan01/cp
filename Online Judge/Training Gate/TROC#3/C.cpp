#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 100*1000;
int N,M;
int a[NMAX+3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++)cin>>a[i];
    int ans[NMAX+3];
    map<int,int> m;
    map<int,int> c;
    int cnt = 0;
    for(int i=1;i<=N;i++){
        int div = (N-a[i])/M;
        int k = a[i]+M*div;
        m[k]++;
        k -= M*(m[k]-1);
        if(k < 0){
            cout << "-1\n"; return 0;
        }
        c[k]++;
        //cout << k << " ";
        ans[i] = k;
    }

    for(int i=1;i<=N;i++){
        if(c[i] == 0){
            cout << "-1\n"; return 0;
        }
    }

    for(int i=1;i<=N;i++){
        cout << ans[i];
        if(i!=N)cout << " ";
    }cout << "\n";
    return 0;
}
