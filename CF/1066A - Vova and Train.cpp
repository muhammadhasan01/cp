#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll T,L,v,l,r, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> L >> v >> l >> r;
        ll x = L/v, y = r/v-l/v; if(l%v==0)y++;
        cout << x-y << "\n";
    }
    return 0;
}
