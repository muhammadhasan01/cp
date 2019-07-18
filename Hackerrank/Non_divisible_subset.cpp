#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define formn(i,n) for(int i=0;i<=(int)n;i++)
#define debug1(i) printf("debug => %ld\n",i);
#define debug2(i,j) printf("debug => %ld - %ld\n",i,j);
#define debug3(i,j,k) printf("debug => %ld - %ld - %ld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,k,a[100003];
int b[103] = {0};


// 0,1,2,3,4,5,6,7,8 => 0,1,2,3,4
/*
    b[0] = 1
    n = 2 -> b[0]+b[1]
    n = 3 -> b[0]+b[1] , b[0]+b[2]
    n = 4 -> b[0]+b[1]+b[2], b[0]+b[2]+b[3]
    n = 5 -> b[0]+b[1]+b[2], b[0]+b[2]+b[4], b[0]+b[1]+b[3],
*/

int solve(){
    form(i,k)cout<<i<<" "<<b[i]<<"\n";
    int ans = 0;
    if(b[0] > 0)ans++;
    if(k&1){
        forn(i,k/2)ans += max(b[i],b[k-i]);
    }else{
        forn(i,k/2-1)ans += max(b[i],b[k-i]);
        if(b[k/2]>0)ans++;
    }
    return max(1,ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    forn(i,n){
        cin>>a[i];
        b[a[i]%k]++;
    }
    cout<<solve()<<"\n";

    return 0;
}
