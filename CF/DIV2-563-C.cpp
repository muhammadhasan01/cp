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
int a[N+10];
int prime[N], f[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=2;i<=N;i++){
        if(prime[i] == 0){
            for(int j=i;j<=N;j+=i){
                prime[j] = i;
            }
        }
    }

    int k = 0;
    forn(i,1,N){
        if(prime[i] == i)f[i] = ++k;
    }

    cin >> n;
    forn(i,2,n){
        cout << f[prime[i]] << " ";
    }


    return 0;
}
