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

const int NMAX = 1000*1000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    bitset<NMAX+2> prime;
    prime.set();
    prime[0] = 0;
    prime[1] = 0;
    for(int i=2;i<=n;i++){
        if(prime[i] == 1){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]){
            cout << i << "\n";
        }
    }
    return 0;
}
