#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define first ff
#define second ss
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll p;
map<ll,ll> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p;
    for(ll i=0; i<=p/2;i++){
        //cout << (i*i)%p << " => " << i << "\n";
        a[(i*i)%p] = i;
    }
    for(ll i=0;i<p;i++){
        if(a[i]==0 && i > 0)a[i]=-1;
        cout << a[i];
        if(i != p-1){
            cout << " ";
        }else{cout << "\n";}
    }
    return 0;
}
