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
int n;
ll a[NMAX+5];
bool y = true;
unordered_set<ll> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int cnt = 0;
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
        s.insert(a[i]);
        if(y && i > 1 && a[i] == a[i-1]){
            y = false;
        }
    }

    if(s.size() < n){
        cout << "0\n";
    }else if(y){
        cout << n+1 << "\n"; return 0;
    }else if(n == 1){
        cout << n << "\n"; return 0;
    }else{
        cout << 1 << "\n";
    }


    return 0;
}
