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
int a[N];
multiset<int> ms;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n;
    forn(i,1,n){
        cin >> a[i];
        ms.insert(a[i]);
    }

    int ans = 0;
    forn(i,1,n){
        auto it = ms.upper_bound(a[i]);
        if(it == ms.end()){
            it = ms.begin();
        }
        if(*it > a[i]){
            ans++;
        }
        //cerr << a[i] << " => " << *it << " => " << ans << "\n";
        ms.erase(it);
    }

    cout << ans << "\n";








    return 0;
}
