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

const int N = 600*1000;
ll a[N+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp, c = 1;
    while(cin>>temp){
        a[c] = temp; c++;
    }
    ll kec = inf, bes = -1;
    for(int i=1;i<c;i++){
        if(a[i] > a[i+1]){
            
        }else if(a[i] < a[i+1]){

        }else{

        }
    }
    return 0;
}
