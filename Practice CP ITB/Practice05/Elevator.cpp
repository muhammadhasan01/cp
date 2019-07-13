#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll F,S,G,U,D, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>F>>S>>G>>U>>D;
    if(S==G){cout << "0\n"; return 0;}
    if((S>G && D == 0) || (S<G && U == 0)){cout << "-1\n"; return 0;}
    ll gcd = __gcd(U,D);
    if(abs(G-S)%gcd!=0){cout << "-1\n"; return 0;}
    while(S != G){
        if(G>S && S+U <= F){S+=U;}
        else if(G>S && S-D >= 1){S-=D;}
        else if(G<S && S-D >= 1){S-=D;}
        else if(G<S && S+U <= F){S+=U;}
        else if(S+U >= F && S-D <= 1){cout << "-1\n"; return 0;}
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
