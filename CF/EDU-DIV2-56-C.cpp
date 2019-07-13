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

int n;
ll a[200000+3], b[100000+3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n/2;i++){
        cin >> b[i];
    }
    a[1] = 0, a[n] = b[1];
    for(int i=2;i<=n/2;i++){
        if(b[i] >= b[i-1]){
            a[n-i+1] = a[n-i+2];
            a[i] = b[i] - a[n-i+1];
        }else if(b[i] < b[i-1]){
            a[i] = a[i-1];
            a[n-i+1] = b[i]-a[i];
        }
    }
    for(int i=1;i<=n/2;i++){
        cout << a[i] << " ";
    }
    for(int i=n/2+1;i<=n;i++){
        cout << b[n+1-i]-a[n+1-i];
        if(i != n){
            cout << " ";
        }
    }cout << "\n";
    return 0;
}
