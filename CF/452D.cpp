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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

ll n,five=5,ans,k,ten[20];
int main()
{
    cin>>n;
    int i;
    if(n<5)
    { cout<<n*(n-1)/2; ex;}
    for(i=0;;i++,five*=10)
        if(five>n)
        {
            k=i;
            break;
        }
    ten[0]=1;
    for(i=1;i<=15;i++)
        ten[i]=ten[i-1]*10;
    for(i=0;i<=8;i++)
    {
        ll num=ten[k]*(1+i)-1;
        ll mid=(ten[k]*(1+i)-1)>>1;
        if(mid>=n) break;
        ans+=min(n*1ll,num-1)-mid;
    }
    cout<<ans << "\n";
    return 0;
}
