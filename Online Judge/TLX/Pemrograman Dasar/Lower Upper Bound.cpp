#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 100000;
int n,q, t1, t2;
int a[N+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+N+1);
    cin >> q;
    while(q--){
        cin >> t1 >> t2;
        cout << upper_bound(a+1,a+N+1,t2)-lower_bound(a+1,a+N+1,t1) << "\n";
    }
    return 0;
}
